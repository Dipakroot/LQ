#ifndef EVENTPICK_H
#define EVENTPICK_H

#include<vector>
#include<string>
#include<set>
#include<iostream>
#include<fstream>
#include<TH1F.h>
#include<TH1D.h>

#include"EventTree.h"
#include"Selector.h"

class EventPick{
public:
	EventPick(std::string titleIn);
	~EventPick();
	
	void process_event(string path, EventTree* inp_tree, Selector* inp_selector, double weight=1.0);
	//void process_event(EventTree* inp_tree, Selector* inp_selector, double weight=1.0);
        void process_event_gen(EventTree* inp_tree, Selector_gen* inp_selector, double weight=1.0);
	void print_cutflow_mu(TH1D* _cutflow);
	void print_cutflow_ele(TH1D* _cutflow);
	void print_cutflow_tau(TH1D* _cutflow); //Added for Tau Analysis

	void init_cutflow_files(string fileName);
	void close_cutflow_files();
	
	struct DiTauInfo
	{
	  DiTauInfo(){};
	  int diTauCharge_;
	  double sumPt_;
	  int index1_;
	  int index2_;
	  float diTauMass_;
	  TLorentzVector lepVector1_;
	  TLorentzVector lepVector2_;

	};

	struct SortDiTauPairs
	{
	  bool operator() (const DiTauInfo t1, const DiTauInfo t2)
	  {
	    // 1st criterion: OS
	    if ( t1.diTauCharge_ < t2.diTauCharge_ ) return true;
	    if ( t1.diTauCharge_ > t2.diTauCharge_ ) return false;
	    // 2nd criterion: sumPt of diTau pair 
	    return (t1.sumPt_ > t2.sumPt_);
	  }
	};
	
	std::string title;
	
	bool saveCutflows;

	std::string year;

	int printEvent;
	bool IsDebug ;
	
	// cuts as parameters, to modify easily
	double MET_cut;
	bool no_trigger;


	int Nlep_eq;
	
	int Njet_ge;
	int NBjet_ge;
	int SkimNjet_ge;
	int SkimNBjet_ge;

	bool ZeroBExclusive;

	bool QCDselect;

	bool applyMetFilter;

	int Jet_Pt_cut_1;
	int Jet_Pt_cut_2;
	int Jet_Pt_cut_3;	
	int Nele_eq;
	int Nmu_eq;
	int NEleVeto_le;
	
        //added for Tau Analysis
        int Ntau_eq;
        int _nTau;
	//float ditau_m;

	int NlooseMuVeto_le;
	int NlooseEleVeto_le;
	int NmediumEleVeto_le;
	
	bool skimEle;
	bool skimMu;

	// variables showing passing or failing selections
	bool passSkim;
	bool passPresel_ele; // passed preselection
	bool passAll_ele; // single flag: event passed all cuts: preselection + photon
	bool passPresel_mu; // passed preselection
	bool passAll_mu; // single flag: event passed all cuts: preselection + photon
	bool passFirstcut; // pass the sync cut	
	bool passTrigger_ele ;
	bool passTrigger_mu ;
	bool passTrigger_tau ;
	bool passFilter ;
	
	//added for Tau Analysis
        bool passPresel_tau;
        bool passAll_tau ;
	bool Pass_trigger_tau;
        

	
	// histograms
	TH1D* cutFlow_mu;
	TH1D* cutFlowWeight_mu;
	TH1D* cutFlow_ele;
	TH1D* cutFlowWeight_ele;
	TH1D* cutFlow_tau; //Added for Tau Analysis
	TH1D* cutFlowWeight_tau; //Added for Tau Analysis

	ofstream dump_input_ele;
	ofstream dump_trigger_ele;
	ofstream dump_lepton_ele;
	ofstream dump_oneJet_ele;
	ofstream dump_twoJet_ele;
	ofstream dump_threeJet_ele;
	ofstream dump_fourJet_ele;
	ofstream dump_btag_ele;

	ofstream dump_input_mu;
	ofstream dump_trigger_mu;
	ofstream dump_lepton_mu;
	ofstream dump_oneJet_mu;
	ofstream dump_twoJet_mu;
	ofstream dump_threeJet_mu;
	ofstream dump_fourJet_mu;
	ofstream dump_btag_mu;

private:
	EventTree* tree;
	Selector* selector;
	
	//	void clear_vectors();
	void set_cutflow_labels_mu(TH1D* hist);
	void set_cutflow_labels_ele(TH1D* hist);
	void set_cutflow_labels_tau(TH1D* hist); //Added for Tau Analysis
};



class EventPick_gen{
public:
        EventPick_gen(std::string titleIn);
        ~EventPick_gen();

        void process_event(EventTree* inp_tree, Selector_gen* inp_selector, double weight=1.0);
        void print_cutflow_mu(TH1D* _cutflow);
        void print_cutflow_ele(TH1D* _cutflow);

        std::string title;

        bool saveCutflows;
        double MET_cut;
        bool no_trigger;

        int Nlep_eq;

        int Njet_ge;
        int NBjet_ge;
        int SkimNjet_ge;
        int SkimNBjet_ge;

        bool ZeroBExclusive;

        int Jet_Pt_cut_1;
        int Jet_Pt_cut_2;
        int Jet_Pt_cut_3;
        int Nele_eq;
        int Nmu_eq;
        int NEleVeto_le;

	//added for Tau Analysis
        int Ntau_eq;

        int NlooseMuVeto_le;
        int NlooseEleVeto_le;
        int NmediumEleVeto_le;

        bool skimEle;
        bool skimMu;

	bool passSkim;
        bool passPresel_ele;
        bool passAll_ele;
        bool passAll_mu;
        bool passPresel_mu;
        bool passFirstcut;
        TH1D* cutFlow_mu;
        TH1D* cutFlowWeight_mu;
        TH1D* cutFlow_ele;
        TH1D* cutFlowWeight_ele;


private:
        EventTree* tree;
        Selector* selector;

	void set_cutflow_labels_mu(TH1D* hist);
        void set_cutflow_labels_ele(TH1D* hist);
};


#endif
