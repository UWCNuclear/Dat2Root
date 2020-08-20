// Run in the command line with: grsisort -l Dat2Root.C
//
// or with:
//
// grsisort -l
// .x Dat2Root.C
//
// or with:
//
// grsisort -l
// .L Dat2Root3.C
// Dat2Root3("somefilename.dat")
//
//  Also, all the above 'grsisort' can be replaced with 'root' - and it should work just fine!
//
//
void Dat2Root(const char *fname="input.dat") {  

   // Initializing the input file
   ifstream infile; 
   infile.open(fname);	

   // A temp storage to hold each line of the input file while we figure out what is in it
   string myline;

   // Because we may not know what is in the file, let's create two variable sized arrays(vectors) to hold the numbers in line
   vector<int>    bins;
   vector<double> values;
    
  
   while(!infile.eof()) {     // Loop over the file
     getline(infile,myline);  // Line-by-line and puts it into our string myline!
     int    bin;
     double value;
     
     std::stringstream ss(myline);  // c++ magic - breaks line up by what spaces and lets us pull out the numbers
     
     ss>>bin;   // First number
     ss>>value; // Second number

     // Store bin and value to make a histogram after the loop
     bins.push_back(bin);  
     values.push_back(value); 
   }

   // Because there is a number on every line of the file, bins.size() and values.size() are the total number of lines in the file,
   // which is the number of bins in the histogram. We can now use this info when we create our histogram.
   TH1F *myhist = new TH1F("myhist","Data from ascii file",bins.size(),0,bins.size());
  
   // NOTE: 
   //   **If MTSort binning is not 1 keV/bin, edit number of bins and maximum! **
   // This info isn't in the file - so one would still have to do this by hand :( 
 
   // Now, let's loop through our data (vectors bins and values) and put it into our histogram.
   for(int x=0;x<bins.size();x++) {

     //  The first bin in a root histogram is 1 unlike every other program who use 0 as the first bin, 
     //  so we set bins[x]+1 here to get the offset right.
     //  Also, using SetBinContent or Fill(bin,value) will make the histogram look right, 
     //  but the number of Entries will be off (Entries==Number of times it is Filled); however, 
     //  the histogram Integral will be correct (Integral==Bumber of COUNTS in the histogram).
     myhist->SetBinContent(bins[x]+1,values[x]); 

     // a way around this would be to comment out the line above and use the 
     // 3 lines below to fill the histogram instead.
     //for(int i=0;i<values[x];i++) {
     //  myhist->Fill(bins[x]+1);
     //} 

   }

   // Formatting of histogram (optional, but you should still do it!)
   myhist->SetTitle("");
   myhist->GetXaxis()->SetTitle("Energy [keV]");
   myhist->GetXaxis()->CenterTitle();
   myhist->GetXaxis()->SetTitleOffset(1);
   myhist->GetXaxis()->SetTitleSize(0.04);
   myhist->GetXaxis()->SetLabelSize(0.04);
   //myhist->GetXaxis()->SetRangeUser(500,1500);
   
   myhist->GetYaxis()->SetTitle("Counts per 1 keV");
   myhist->GetYaxis()->CenterTitle();
   myhist->GetYaxis()->SetTitleOffset(1.1);
   myhist->GetYaxis()->SetTitleSize(0.04);
   myhist->GetYaxis()->SetLabelSize(0.04);
   //myhist->GetYaxis()->SetRangeUser(0,400);
   //TGaxis::SetMaxDigits(4);


   printf(" I found %lu lines!\n",bins.size());
   myhist->Draw();
 
   // root is not good at remembering where it is working once a file is open, so we will remind him where we are.
   TDirectory *current = gDirectory; 

 //Now that we have everything filled, formated and drawn - let's save it

// Initializing output file 
// Edit output file name!
   TFile *output = new TFile("output.root","RECREATE");


   // Close the input file
   infile.close();

   // Save a copy of myhist to the output root file
   myhist->Write();
   
   // Close the output root file - this will leave the working directory hanging
   output->Close();

   // Go back to the working directory
   current->cd();

// Now you can change the names to be more descriptive :-)

}
