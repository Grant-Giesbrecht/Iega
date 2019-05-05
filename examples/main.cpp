//
//  main.cpp
//  KMatrix
//
//  Created by Grant Giesbrecht on 1/26/18.
//  Copyright © 2018 IEGA. All rights reserved.
//

#include <iostream>

#include "KMatrix.hpp"
#include "KVector.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    KMatrix<double> m1("1, 2;3, 4");
    m1(0, 0) = 10;
    cout << "Rows: " << m1.rows() << " Cols: " << m1.cols() << endl;
    cout << endl;
    cout << m1.to_string("|m") << endl;
    cout << "Max: " << m1.max() << endl;
    cout << "Min: " << m1.min() << endl;
    cout << "Avg: " << m1.avg() << endl;
    
    KMatrix<std::string> m2(2, 3);
    m2(0, 0) = "string_ one";
    m2(0, 1) = ":)";
    m2(1, 0) = "I am a cool";
    m2(1, 1) = ":}";
    cout << m2.to_string("[m") << endl;
    
//    KMatrix<bool> m3(2, 2);
//    bool& a = m3.mat[0][0];
//    double& b = m1.mat[0][0];s
    
//    if (m3(0, 0)){
//        cout << "True" << endl;
//    }
    
    KMatrix<int> m3(2, 2);
    m3(0, 0) = 14;
    m3(0, 1) = -3;
    m3(1, 0) = 10;
    m3(1, 1) = -15;
    cout << '\n' << m3.to_string("|m") << endl;
    
    KMatrix<int> m3_2("1, 5;-12, 10");
    cout << m3_2.to_string("]") << endl;
    m3_2 += m3;
    
    cout << m3_2.to_string("]") << endl;
    
    KMatrix<int> m4 = m3 + m3_2;
    cout << m4.to_string() << endl;
    
    KMatrix<double> km_a("-4, 3.2; 19, 12.01");
    
    KMatrix<double> km_b("19, 0; 1.5, -2");
    km_a.setElementMultMode(true);
    km_b.setElementMultMode(true);
    cout << "Is element: " << bool_to_str(km_a.getElementMultMode()) << endl;
    KMatrix<double> km_ab = km_a * km_b;
    KMatrix<double> km_adb = km_a / km_b;
    cout << "\n\nDoubles:\n\tKM_A: " << km_a.to_string() << "\n\tKM_B: " << km_b.to_string() << "\n\tProd: " << km_ab.to_string();
    cout << "\n\tDiv: " << km_adb.to_string() << endl;
    cout << "\nStdev: " << to_string(km_a.stdev()) << endl;
    
    KMatrix<double> km_d1(-14.303, 2, 5);
    cout << km_d1.to_string("|m") << endl;
	
	KVector<double> kv("1, 2, 3, 10, 9, 8, 7, 6, 5, 4");
	cout << kv.to_string("|") << endl;
	cout << kv[4] << endl;
	kv.clear();
	cout << kv.to_string("|") << endl;
	
//    m3(0, 0) = true;
//    m3(0, 1) = false;
//    m3(1, 0) = false;
//    m3(1, 1) = true;
//    cout << "double: " << typeid(double).name() << endl;
//    cout << "string: " << typeid(string).name() << endl;
//    cout << "int: " << typeid(int).name() << endl;
//    cout << "char: " << typeid(char).name() << endl;
//    cout << "bool: " << typeid(bool).name() << endl;
//    cout << "long: " << typeid(long).name() << endl;
//    cout << "long long: " << typeid(long long).name() << endl;
//    cout << "\tlong long int: " << typeid(long long int).name() << endl;
//    cout << "unsigned: " << typeid(unsigned).name() << endl;
//    cout << "unsigned long: " << typeid(unsigned long).name() << endl;
//    cout << "unsigned long long: " << typeid(unsigned long long).name() << endl;
//    cout << "float: " << typeid(float).name() << endl;
//    cout << "long double: " << typeid(long double).name() << endl;
//    cout << "\n\n\n";
    
//    unsigned long long int  x = 15;
//    cout << limited_template_to_string(x) << endl;
    
    /*
     string (int val);
     string to_string (long val);
     string to_string (long long val);
     string to_string (unsigned val);
     string to_string (unsigned long val);
     string to_string (unsigned long long val);
     string to_string (float val);
     string to_string (double val);
     string to_string (long double val)
     */
    
    std::cout << "Hello, World!\n";
	
	KMatrix<std::string> kms("\"Hello there\", \"THis is string\" ; \" Fuck you all \", \" Alles was ich will \"  ");
	cout << kms.to_string("|m") << endl;
	
	KMatrix<bool> kmb("True, False, True; false, trUe, true");
	cout << kmb.to_string("[") << endl;
	
	KVector<double> kvtest = KVec::makeRange(0, 1.5, 10);
	kvtest *= 2;
	cout << kvtest.to_string() << endl;
	
	KMatrix<double> log_test = KVec::makeLogRange(0, 3, 100, 1);
	cout << log_test.to_string() << endl;
	
    return 0;
}


























