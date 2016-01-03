//grab all text files, plug into one new txt file (each column is each text file, seperate column by a tab), calculate average and standard deviation
//the original
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "dirent.h"

using namespace std;

int main(){
	cout << "This program collects PL data files from spectrasuite and compiles it into"<<endl
	     << "one txt file, along with calculating averages and standard deviation!" <<endl
	     << "To use it, make sure there are 15 (no more no less) txt" <<endl
	     << "files in the directory and nothing else, then type the directory below."<<endl
	     << "This program is work in progress, there may be bugs and other small issues."<<endl
	     << "Use at your discretion! - Written by Loren Yeung v1.0 2015"<<endl<<endl
	     << "Enter directory:"<<endl;
	char dirname[256];
	while(cin.getline(dirname,256)){
		ifstream record[20];
		string files[20];
		string justfiles[20];
		double numbers[40000];
		//directory code
		DIR *dir;
		struct dirent *ent;
		int i=0;
		if ((dir = opendir (dirname)) != NULL) {
		  /* print all the files and directories within directory */
			
		  while ((ent = readdir (dir)) != NULL) {
		    //printf ("%s\n", ent->d_name);
		    justfiles[i]= ent->d_name;
		    string temp;
		    temp.append(dirname);
		    temp.append("\\");
		    temp.append(ent->d_name);
		    files[i] = temp;
		    i=i+1;
		  }

		  int counter = 0;
		string line;
		for(int j =2;j<17;j++){
		cout << files[j]<< "\n";
			record[j].open(files[j]);
			
				while(getline(record[j],line)){
					istringstream iss(line);
					int num = 0;
					if(!(iss >> num).fail()) { //checks for numbers only
					int count = 0;
				    while (iss) {
				        string word;
				        iss >> word;
				        if(count == 1){
				        	numbers[counter] = stod(word);
				        	counter++;	}
				        count++;
				    }}
				}
				record[j].close();	
		}
		closedir (dir);
		} else {
		  /* could not open directory */
		  perror ("");
		  return EXIT_FAILURE;
		}
		//end directory code

		double list0[2048];
		double list1[2048];
		double list2[2048];
		double list3[2048];
		double list4[2048];
		double list5[2048];
		double list6[2048];
		double list7[2048];
		double list8[2048];
		double list9[2048];
		double list10[2048];
		double list11[2048];
		double list12[2048];
		double list13[2048];
		double list14[2048];
		double list15[2048]; //avg
		double list16[2048]; //stdev.p
		double list17[2048]; //stdev.s

		string fileout ="Combined_Output-";
		fileout.append(justfiles[2]);
		ofstream reportfile (fileout);
		for (int i = 0;i< 15;i++)
			reportfile <<"#"<<i<<'\t';
		reportfile << "avg \t stdev.p\tstdev.s"<<endl; 
		for (int i = 0; i<2048;i++){
			list0[i]=numbers[i];
			list1[i]=numbers[i+2048];
			list2[i]=numbers[i+4096];
			list3[i]=numbers[i+6144];
			list4[i]=numbers[i+8192];
			list5[i]=numbers[i+10240];
			list6[i]=numbers[i+12288];
			list7[i]=numbers[i+14336];
			list8[i]=numbers[i+16384];
			list9[i]=numbers[i+18432];
			list10[i]=numbers[i+20480];
			list11[i]=numbers[i+22528];
			list12[i]=numbers[i+24576];
			list13[i]=numbers[i+26624];
			list14[i]=numbers[i+28672];
			list15[i]=(list0[i]+list1[i]+list2[i]+list3[i]+list4[i]+list5[i]+list6[i]+list7[i]+list8[i]+list9[i]+list10[i]+list11[i]+list12[i]+list13[i]+list14[i])/15;
			list16[i]=sqrt(
				(
					(list15[i]-list0[i])*(list15[i]-list0[i])+
					(list15[i]-list1[i])*(list15[i]-list1[i])+
					(list15[i]-list2[i])*(list15[i]-list2[i])+
					(list15[i]-list3[i])*(list15[i]-list3[i])+
					(list15[i]-list4[i])*(list15[i]-list4[i])+
					(list15[i]-list5[i])*(list15[i]-list5[i])+
					(list15[i]-list6[i])*(list15[i]-list6[i])+
					(list15[i]-list7[i])*(list15[i]-list7[i])+
					(list15[i]-list8[i])*(list15[i]-list8[i])+
					(list15[i]-list9[i])*(list15[i]-list9[i])+
					(list15[i]-list10[i])*(list15[i]-list10[i])+
					(list15[i]-list11[i])*(list15[i]-list11[i])+
					(list15[i]-list12[i])*(list15[i]-list12[i])+
					(list15[i]-list13[i])*(list15[i]-list13[i])+
					(list15[i]-list14[i])*(list15[i]-list14[i])
				)/15);
					list17[i]=sqrt(
				(
					(list15[i]-list0[i])*(list15[i]-list0[i])+
					(list15[i]-list1[i])*(list15[i]-list1[i])+
					(list15[i]-list2[i])*(list15[i]-list2[i])+
					(list15[i]-list3[i])*(list15[i]-list3[i])+
					(list15[i]-list4[i])*(list15[i]-list4[i])+
					(list15[i]-list5[i])*(list15[i]-list5[i])+
					(list15[i]-list6[i])*(list15[i]-list6[i])+
					(list15[i]-list7[i])*(list15[i]-list7[i])+
					(list15[i]-list8[i])*(list15[i]-list8[i])+
					(list15[i]-list9[i])*(list15[i]-list9[i])+
					(list15[i]-list10[i])*(list15[i]-list10[i])+
					(list15[i]-list11[i])*(list15[i]-list11[i])+
					(list15[i]-list12[i])*(list15[i]-list12[i])+
					(list15[i]-list13[i])*(list15[i]-list13[i])+
					(list15[i]-list14[i])*(list15[i]-list14[i])
				)/14);
			reportfile << list0[i] <<"\t" <<list1[i] <<"\t" <<list2[i] <<"\t" <<list3[i]<<"\t" <<list4[i]<<"\t" <<list5[i]<<"\t" <<list6[i]<<"\t" <<list7[i]<<"\t" <<list8[i]<<"\t" <<list9[i]<<"\t" <<list10[i] <<"\t" <<list11[i]<<"\t" <<list12[i]<<"\t" <<list13[i]<<"\t" <<list14[i]<<"\t" <<list15[i] <<"\t" <<list16[i] <<"\t" <<list17[i] << endl;

		}
		reportfile.close();
		cout <<"Enter another directory or Control-C to quit:"<<endl;
	}
}

