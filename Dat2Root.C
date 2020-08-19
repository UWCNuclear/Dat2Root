// Run in the command line with: grsisort -l Dat2Root3.C
// or with:
// grsisort -l
// .x Dat2Root.C

#include "Riostream.h"
void Dat2Root() {

// Initializing input file 
// Edit input file name!
   ifstream in;
   in.open(Form("input.dat"));

// Initializing output file 
// Edit output file name!
   TFile *output = new TFile("output.root","RECREATE");

// Initializing root histogram (TH1)
// If MIDAS binning is not 1 keV/bin, edit number of bins and maximum!
   Float_t x,y;
   Int_t nlines = 0;
   TH1F *myhist = new TH1F("myhist","Data from ascii file",16384,0,16383);
//   TNtuple *ntuple = new TNtuple("ntuple","Data from ascii file","x:y");

// Filling root histogram (TH1)
  while (in >> x >> y) {
      if (!in.good()) break;
//      printf("x=%8f, y=%8f\n",x,y);
      myhist->Fill(x,y);
//      ntuple->Fill(x,y);
      nlines++;
   }

   printf(" I found %d lines!\n",nlines);

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

// Drawing histogram
//   myhist->Draw();

//Writing output file, and closing input and output files
   in.close();

   output->Write();

   output->Close();

// Now you can change the names to be more descriptive :-)

}