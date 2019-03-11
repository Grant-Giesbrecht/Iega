#include <IEGA/iega.hpp>
#include <stdio.h>
#include <iostream>
#include "KVar.hpp"
#include <string>

using namespace std;

int main(){
	
	//Initialize KV read/writer
	KVar kv;
	long fl;

	//Load example.kv1
	if (kv.load_KV1("example.kv1", fl)){
		cout << "Read success" << endl;
	}else{
		cout << "Read failed. EC: " << fl << endl;
	}
	cout << kv.num_variables() << endl;
	kv.print();

	//Clear kv read/writer
	kv.clear();

	//Create matricies
	KMatrix<double> kmd("1, 2, 3;, 4, 5, 6; 9.8, 10.7, 11.6");
	KMatrix<string> kms("\"Yo!\", \"Hiya\"");
	KMatrix<bool> kmb("True, False, T");

	//Write variables to file
	kv.add_double("D1test", 7.6, "Hallooo");
	kv.add_variable("B1test", false, "WHAT THE FACK");
	kv.add_variable("S1test", "This is a string, I think", "None of your business");
	kv.add_variable("m1test", kmd, "Okay, this is cool but old hat");
	kv.add_variable("m2test", kmb, "Okay, this is new, but not very useful...");
	kv.add_variable("m3test", kms, "Now *THIS* is dope as SHIT. Hells yeah" );
	kv.write_KV1("example_out.kv1");

	kv.clear();

	kv.load_KV1("example_out.kv1");
	cout << endl << kv.get_comment("D1test") << endl << endl;
	kv.print();
	
	
	
	
	
	return 0;
}
