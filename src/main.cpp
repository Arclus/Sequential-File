#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib> // srand and rand
#include <ctime> // time
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;


const char* mFile = "man.txt";
const char* wFile = "woman.txt";
const char* sFile = "surname.txt";
const char* oFile1 = "randomStudent.txt";
const char* oFile2 = "sequentialGano.txt";
const char* oFile3 = "sortedGano.txt";
const char* oFile4 = "sortedStudentNumber.txt";
const char* oFile5 = "sortedGenderMan.txt";
const char* oFile6 = "sortedGenderWoman.txt";
const char* oFile7 = "sortedClass1.txt";
const char* oFile8 = "sortedClass2.txt";
const char* oFile9 = "sortedClass3.txt";
const char* oFile10 = "sortedClass4.txt";


ofstream o1(oFile1, ios::out);
ofstream o2(oFile2, ios::out);
ofstream o3(oFile3, ios::out);
ofstream o4(oFile4, ios::out);
ofstream o5(oFile5, ios::out);
ofstream o6(oFile6, ios::out);
ofstream o7(oFile7, ios::out);
ofstream o8(oFile8, ios::out);
ofstream o9(oFile9, ios::out);
ofstream o10(oFile10, ios::out);
	
ifstream mF(mFile, ios::in);
ifstream wF(wFile, ios::in);
ifstream sF(sFile, ios::in);
ifstream oP2(oFile2, ios::in);
ifstream oP3(oFile2, ios::in);

std::clock_t start1, start2, start3, start4, start5;

double duration1 = 0, duration2 = 0, duration3 = 0, duration4 = 0, duration5 = 0;


struct people{
	
	string name;
	string surName;
	string gender;
	
	int studentNumber;
	int classNumber;
	int classSequenceNumber;
	int sectionSequenceNumber;
	
	float gano;
	
}student[10000];


bool here(int studentNumberTemp)
{
	bool back = false;
	
	for(int i = 0 ; i < 10000; i++)
	{
		
		if(student[i].studentNumber == studentNumberTemp)
		{
			back = false;
		}
		
		else
		{
			back = true;
			
			break;
		}				
	}
	
	return back;	
}


int checkSectionNumber(int studentNumber)
{
	int h = 0, studentNumberTemp = 0, sectionSequenceNumberTemp = 0, checkedSectionNumber = 0, k = 0;
	
	string word, line;
	
	
	ifstream oP9(oFile3, ios::in);

	if (!oP9)
	{
    	cout << "ERROR!! - FILE CAN NOT OPEN - oP9 " << endl;

    	//return (-1);
	}

	while (getline(oP9, line)  && (k == 0))
	{
    	stringstream ss(line);

    	while (getline(ss, word, ';'))
    	{
       	
		   	if (h == 0)
        	{
            	studentNumberTemp = atoi(word.c_str());
        	}
        	
        	else if (h == 6)
        	{
            	sectionSequenceNumberTemp = atoi(word.c_str());
        	}

        	else if (h == 7)
        	{

            	if ((studentNumberTemp == studentNumber))  
            	{

					checkedSectionNumber = sectionSequenceNumberTemp;
					
					k = 1;
					
					return checkedSectionNumber;
					
					
					break;									
            	}

            	h = 0;

            	continue;
        	}

        	h++;
    	}
	}
	
	oP9.close();
}


int checkClassNumber(int studentNumber, int classNumber)
{
	int k = 0, h = 0, checkedClassNumber = 0, studentNumberTemp = 0, classSequenceNumberTemp = 0;
	
	string word, line;
	
	const char* oFile15 = "sortedClass1.txt";
	const char* oFile16 = "sortedClass2.txt";
	const char* oFile17 = "sortedClass3.txt";
	const char* oFile18 = "sortedClass4.txt";
	
	if (classNumber == 1)
	{
		ifstream oP10(oFile7, ios::in);
		
		if (!oP10)
		{
    		cout << "ERROR!! - FILE CAN NOT OPEN - oP10 " << endl;

    		return (-1);
		}

		while (getline(oP10, line)  && (k == 0))
		{
	    	stringstream ss(line);
	
	    	while (getline(ss, word, ';'))
	    	{
	       	
			   	if (h == 0)
	        	{
	            	studentNumberTemp = atoi(word.c_str());
	        	}
	        	
	        	else if (h == 7)
	        	{
					classSequenceNumberTemp = atoi(word.c_str());
					
	            	if ((studentNumberTemp == studentNumber))  
	            	{
	
						checkedClassNumber = classSequenceNumberTemp;
						
						k = 1;
						
						return checkedClassNumber;
	
						break;								
	            	}
	
	            	h = 0;
	
	            	continue;
	        	}
	
	        	h++;
	    	}
		}
	
		oP10.close();
	}
	
	else if (classNumber == 2)
	{
		ifstream oP11(oFile8, ios::in);
		
		if (!oP11)
		{
    		cout << "ERROR!! - FILE CAN NOT OPEN - oP11 " << endl;

    		return (-1);
		}

	while (getline(oP11, line)  && (k == 0))
	{
    	stringstream ss(line);

    	while (getline(ss, word, ';'))
    	{
       	
		   	if (h == 0)
        	{
            	studentNumberTemp = atoi(word.c_str());
        	}
        	
        	else if (h == 7)
        	{
				classSequenceNumberTemp = atoi(word.c_str());
				
            	if ((studentNumberTemp == studentNumber))  
            	{

					checkedClassNumber = classSequenceNumberTemp;
					
					k = 1;
					
					return checkedClassNumber;

					break;							
            	}

            	h = 0;

            	continue;
        	}

        	h++;
    	}
	}
	
	oP11.close();
	}
	
	else if (classNumber == 3)
	{
		ifstream oP12(oFile9, ios::in);
		
		if (!oP12)
		{
    		cout << "ERROR!! - FILE CAN NOT OPEN - oP12 " << endl;

    		return (-1);
		}

	while (getline(oP12, line)  && (k == 0))
	{
    	stringstream ss(line);

    	while (getline(ss, word, ';'))
    	{
       	
		   	if (h == 0)
        	{
            	studentNumberTemp = atoi(word.c_str());
        	}
        	
        	else if (h == 7)
        	{
				classSequenceNumberTemp = atoi(word.c_str());
				
            	if ((studentNumberTemp == studentNumber))  
            	{

					checkedClassNumber = classSequenceNumberTemp;
					
					k = 1;
					
					return checkedClassNumber;

					break;							
            	}

            	h = 0;

            	continue;
        	}

        	h++;
    	}
	}
	
	oP12.close();
	}
	
	else if (classNumber == 4)
	{
		ifstream oP13(oFile10, ios::in);
		
		if (!oP13)
		{
    		cout << "ERROR!! - FILE CAN NOT OPEN - oP13 " << endl;

    		return (-1);
		}

	while (getline(oP13, line)  && (k == 0))
	{
    	stringstream ss(line);

    	while (getline(ss, word, ';'))
    	{
       	
		   	if (h == 0)
        	{
            	studentNumberTemp = atoi(word.c_str());
        	}
        	
        	else if (h == 7)
        	{
				classSequenceNumberTemp = atoi(word.c_str());
				
            	if ((studentNumberTemp == studentNumber))  
            	{

					checkedClassNumber = classSequenceNumberTemp;
					
					k = 1;
					
					return checkedClassNumber;

					break;						
            	}

            	h = 0;

            	continue;
        	}

        	h++;
    	}
	}
	
	oP13.close();
	}
}


int callGano()
{
	start5 = std::clock();
	
	int c1 = 0;
	int c2 = 2500;
	int c3 = 5000;
	int c4 = 7500;
	
	string word, line, line2, nameTemp, surnameTemp, genderTemp, ganoTemp, temp, x;
	string ganoReady2[4001];
	
	int h = 0, studentNumberTemp = 0, classNumberTemp = 0, s = 0, b = 0, l = 0, p = 0, m = 0, sectionSequenceNumberTemp = 0, classSequenceNumberTemp = 0;
	float gano[10000];
	float ganoTemp2 = 0.000;
	double ganoReady[4001];
	
	for (double y = 0.000; y <= 4.000; y = y + 0.001)  //for gano numbers
    {
            ganoReady[s] = y;
            s++;
    }


    if(!o2)
    {
            cout << "ERROR!! - FILE CAN NOT OPEN - 3" << endl;

            return -1;
    }

    else   // gano numbers text
    {
        for( int i = 0; i < 4001; i++)
        {
            o2 << fixed << setprecision(3) << ganoReady[i] << endl;
        }
    }

    o2.close();
    

    if ( (!oP3) )
    {
        cout << "ERROR!! - FILE CAN NOT OPEN - 9" << endl;  
    }
    
    else if (oP3.is_open())
	{
		while (getline(oP3, line2))
    	{
        	ganoReady2[b] = line2;
        	b++;
    	}	
	}
    
    for (int i = 0; i < 4001; i++)  //test for gano numbers.
    {
		//cout << fixed << setprecision(3) << ganoReady2[i] << endl;
    }
	
	for (float i = 0.000; i <= 4.000; (i = i + 0.001))  
	{
		
    	ifstream oP7(oFile1, ios::in);

    	if (!oP7)
    	{
        	cout << "ERROR!! - FILE CAN NOT OPEN - 10 " << endl;

        	return (-1);
    	}

    	while (getline(oP7, line))    //class sort with gano sort
    	{
        	stringstream ss(line);

        	while (getline(ss, word, ';'))
        	{
           	
			   	if (h == 0)
            	{
                	studentNumberTemp = atoi(word.c_str());
            	}

            	else if (h == 1)
            	{
                	classNumberTemp = atoi(word.c_str());
            	}

            	else if (h == 2)
            	{
                	nameTemp = word;
           	 	}

            	else if (h == 3)
            	{
                	surnameTemp = word;
            	}

            	else if (h == 4)
            	{
                	genderTemp = word;
            	}

				else if (h == 5)
            	{ 		
            		x = word;
            		
            		istringstream iss(word);

                	iss >> ganoTemp2;
            	}
            	
            	else if (h == 6)
            	{
            		sectionSequenceNumberTemp = atoi(word.c_str());
				}

            	else if (h == 7)
            	{
                	classSequenceNumberTemp = atoi(word.c_str());

                	if (ganoReady2[p] == x)
                	{
                        if (classNumberTemp == 1)
                        {
						                       	
                            student[c1].studentNumber = studentNumberTemp;
                            student[c1].classNumber = classNumberTemp;
                            student[c1].name = nameTemp;
                            student[c1].surName = surnameTemp;
                            student[c1].gender = genderTemp;
                            student[c1].gano = ganoTemp2;
                            student[c1].sectionSequenceNumber = sectionSequenceNumberTemp;
                    		student[c1].classSequenceNumber = classSequenceNumberTemp;
                        
                            //cout << c1 << " " << student[c1].studentNumber << " " << student[c1].classNumber << " " << student[c1].name << " " << student[c1].surName << " " << student[c1].gender << " " << fixed << setprecision(3) << student[c1].gano << endl;
                            c1++;
                        }

                        else if ((classNumberTemp == 2))
                    	{

                        	student[c2].studentNumber = studentNumberTemp;
                        	student[c2].classNumber = classNumberTemp;
                        	student[c2].name = nameTemp;
                        	student[c2].surName = surnameTemp;
                        	student[c2].gender = genderTemp;
                       		student[c2].gano = ganoTemp2;
                       		student[c2].sectionSequenceNumber = sectionSequenceNumberTemp;
                    		student[c2].classSequenceNumber = classSequenceNumberTemp;
                        
                        	//cout << c2 << " " << student[c2].studentNumber << " " << student[c2].classNumber << " " << student[c2].name << " " << student[c2].surName << " " << student[c2].gender << " " << fixed << setprecision(3) << student[c2].gano << endl;
                        	c2++;
                    	}
                    
                    	else if ((classNumberTemp == 3))
                    	{

                        	student[c3].studentNumber = studentNumberTemp;
                        	student[c3].classNumber = classNumberTemp;
                        	student[c3].name = nameTemp;
                        	student[c3].surName = surnameTemp;
                        	student[c3].gender = genderTemp;
                        	student[c3].gano = ganoTemp2;
                        	student[c3].sectionSequenceNumber = sectionSequenceNumberTemp;
                    		student[c3].classSequenceNumber = classSequenceNumberTemp;
                        
                        	//cout << c3 << " " << student[c3].studentNumber << " " << student[c3].classNumber << " " << student[c3].name << " " << student[c3].surName << " " << student[c3].gender << " " << fixed << setprecision(3) << student[c3].gano << endl;
                        	c3++;
                    	}
                    
                    	else if ((classNumberTemp == 4))
                    	{

                        	student[c4].studentNumber = studentNumberTemp;
                        	student[c4].classNumber = classNumberTemp;
                        	student[c4].name = nameTemp;
                        	student[c4].surName = surnameTemp;
                        	student[c4].gender = genderTemp;
                        	student[c4].gano = ganoTemp2;                            
							student[c4].sectionSequenceNumber = sectionSequenceNumberTemp;
                    		student[c4].classSequenceNumber = classSequenceNumberTemp;
                        
                        	//cout << c4 << " " << student[c4].studentNumber << " " << student[c4].classNumber << " " << student[c4].name << " " << student[c4].surName << " " << student[c4].gender << " " << fixed << setprecision(3) << student[c4].gano << endl;
                        	c4++;
                    	}
                    	
                	}
                	
                	h = 0;

                	continue;
            	}

            	h++;
        	}
    	}
    	
    	p++;

    	oP7.close();
    	
	}

	
	for (int i = 0; i < 10000; i++)
    {
        
        if (i < 2500)
        {
        	student[i].classSequenceNumber = 2500 - i;
		}
		
		else if (i >= 2500 && i < 5000)
		{
			student[i].classSequenceNumber = 5000 - i;
		}
		
		else if (i >= 5000 && i < 7500)
		{
			student[i].classSequenceNumber = 7500 - i;
		}
		
		else if ( i >= 7500)
		{
			student[i].classSequenceNumber = 10000 - i;
		}
     
    }
    
    
    
    if (!o7 || !o8 || !o9 || !o10)
    {
        cout << "ERROR!! - FILE CAN NOT OPEN 6" << endl;

        return -1;
    }

    else
    {
    	int q = 0;
    	
        for (int i = 0; i < 10000; i++)   // sorting gano
        {
        	//q = checkSectionNumber(student[i].studentNumber);
        
        	
        	if ( i < 2500)
        	{
        		q = checkSectionNumber(student[i].studentNumber);
        		o7 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed << setprecision(3) << student[i].gano << ";" <<  q << ";" << student[i].classSequenceNumber <<endl;
			}
			
			else if ( i >= 2500 && i < 5000)
			{
				q = checkSectionNumber(student[i].studentNumber);
				o8 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed << setprecision(3) << student[i].gano << ";" <<  q << ";" << student[i].classSequenceNumber <<endl;

			}
			
			else if ( i >= 5000 && i < 7500)
			{
				q = checkSectionNumber(student[i].studentNumber);
				o9 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed << setprecision(3) << student[i].gano << ";" <<  q << ";" << student[i].classSequenceNumber <<endl;
			}
			
			else if ( i >= 7500)
			{
				q = checkSectionNumber(student[i].studentNumber);
				o10 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed << setprecision(3) << student[i].gano << ";" <<  q << ";" << student[i].classSequenceNumber <<endl;
			}
        }
    }
    
    duration5 = ( std::clock() - start5 ) / (double) CLOCKS_PER_SEC;
    cout << "Time of sorting Gano with Class Numbers : " <<  fixed << duration5 << endl;
    
}



int main(int argc, char** argv)
{
	start1 = std::clock();
	
	setlocale(LC_ALL, "Turkish");
		
	string manName[5000];
	string womanName[5000];
	string surName[2446];
	string word, line, line2, nameTemp, surnameTemp, genderTemp, ganoTemp, temp, x;
	string ganoReady2[4001];
	
	int studentNumber[10000];
	int classNumber[10000];
	int m = 0, w = 0, p = 0, k = 0, h = 0, l = 0, j = 0, g = 0, t = 0, kS = 0, eS = 0, studentNumberTemp = 0, classNumberTemp = 0, b = 0, s = 0, v = 0, classSequenceNumberTemp = 0, sectionSequenceNumberTemp = 0;

	float gano[10000];
	float ganoTemp2 = 0.000;
	double ganoReady[4001];
	
	bool back;
	
	
	if (!mF || !wF || !sF)
	
	{
		cout << "ERROR!! - FILE CAN NOT OPEN - 1";
		
		return(-1);
	}
	
	else if (mF.is_open() || wF.is_open() || sF.is_open())  //for names and surnames
	
	{	
		int k = 1;
		
		for (int i = 0; i < k; i++)
		
		{
			
			if ( mF.eof() )
			{
				mF.close();
			}
			
			else if( (!(mF.eof())) && (mF.is_open()) )
			{
				mF >> manName[i];
			}
			
			if ( wF.eof() )
			{
				wF.close();
			}
			
			else if( (!(wF.eof())) && (wF.is_open()) )
			{
				wF >> womanName[i];
			}
			
			if ( sF.eof() )
			{
				sF.close();
			}
			
			else if( (!(sF.eof())) && (sF.is_open()) )
			{
				sF >> surName[i];
			}
			
			
			if ( (wF.eof()) && (mF.eof()) && (sF.eof()) )
			{
				break;
			}
			
			k++;
		}
	}
	
	for (int i = 0; i < 10000; i++)  //for class numbers
	{
		if (i < 2500)
		{
			classNumber[i] = 1;
		}
		
		else if (i >= 2500 && i < 5000)
		{
			classNumber[i] = 2;
		}
		
		else if (i >= 5000 && i < 7500)
		{
			classNumber[i] = 3;
		}
		
		else
		{
			classNumber[i] = 4;
		}
	}
	
	for(int i = 0; i < 10000; i++)	// for student numbers
	{
		studentNumber[i] = i + 1;
	}
	
	srand(time(NULL));
	
	for ( int i = 0; i < 10000; i++)  //suffle
	{
		int random1, random2, random3, random4, random5, random6, random7, random8, random9, random10, number1;
		
		string name1;
		
		
		random1 = rand() % 5000;
		random2 = rand() % 5000;
		
		random3 = rand() % 5000;
		random4 = rand() % 5000;
		
		random5 = rand() % 2445;
		random6 = rand() % 2445;
		
		random7 = rand() % 10000;
		random8 = rand() % 10000;
		
		random9 = rand() % 10000;
		random10 = rand() % 10000;
		
		name1 = manName[random1];
		manName[random1] = manName[random2];
		manName[random2] = name1;
		
		name1 = womanName[random3];
		womanName[random3] = womanName[random4];
		womanName[random4] = name1;
		
		
		name1 = surName[random5];
		surName[random5] = surName[random6];
		surName[random6] = name1;
		
		number1 = classNumber[random7];
		classNumber[random7] = classNumber[random8];
		classNumber[random8] = number1;
		
		number1 = studentNumber[random9];
		studentNumber[random9] = studentNumber[random10];
		studentNumber[random10] = number1;
	}
	
	cout.precision(3);  // after point three digit
	
	for ( int i = 0; i < 10000; i++ )  //for gano
    {
    	gano[i] = (4.0 * (rand() / (double)RAND_MAX));

        //cout << gano[i] << fixed << endl;
    }
    
    for (int i = 0; i < 5000; i++)  //test for names
	{
		//cout << womanName[i] << endl;
		//cout << manName[i] << endl;
	}
	
	for (int i = 0; i < 2445; i++)  // test for surnames
	{
		//cout << surName[i] << endl;
	}
	
	for (int i = 0; i < 10000; i++)  //test for classNumber and studentNumber
	{
		//cout << classNumber[i] << endl;
		//cout << studentNumber[i] << endl;
	}
	
	
	if (!o1)
	{
		cout << "ERROR!! - FILE CAN NOT OPEN - 2" << endl;
		
		return -1;
	}
	
	else if( o1.is_open() ) // first output1 - random students
	{
		for (int i = 0; i < 10000; i++)
		{
			int surNameRandom, genderRandom;
		
			surNameRandom = rand() % 2445;
			genderRandom = rand() % 2;
		
			if ( ( (genderRandom == 0) && (m < 5000) ) || (w > 4999) )
			{
			
				o1 << studentNumber[i] << ";" << classNumber[i] << ";" << manName[m] << ";" << surName[surNameRandom] << ";" << "E" << ";" << fixed << setprecision(3) << gano[i] << ";" << "0" << ";" << "0" << endl;
				m++;
			}
		
			else if ( ( (genderRandom == 1) && (w < 5000) ) || (m > 4999) )
			{
				o1 << studentNumber[i] << ";" << classNumber[i] << ";" << womanName[w] << ";" << surName[surNameRandom] << ";" << "K" << ";" << fixed << setprecision(3) << gano[i] << ";" << "0" << ";" << "0" << endl;
				w++;
			}
		}
	}

	o1.close();
	
	
    for (double y = 0.000; y <= 4.000; y = y + 0.001)  //for gano numbers
    {
            ganoReady[s] = y;
            s++;
    }


    if(!o2)
    {
            cout<< "ERROR!! - FILE CAN NOT OPEN - 3" << endl;

            return -1;
    }

    else   // gano numbers text
    {
        for( int i = 0; i < 4001; i++)
        {
            o2 << fixed << setprecision(3) << ganoReady[i] << endl;
        }
    }

    o2.close();
    

    if ( (!oP2) )
    {
        cout << "ERROR!! - FILE CAN NOT OPEN - 4" << endl;
    }
    
    else if (oP2.is_open())
	{
		while (getline(oP2, line2))
    	{
        	ganoReady2[b] = line2;
        	b++;
    	}	
	}
    
    for (int i = 0; i < 4001; i++)  //test for gano numbers.
    {
        // cout << fixed << setprecision(3) << ganoReady2[i] << endl;
    }
    
    
        
    duration1 = ( std::clock() - start1 ) / (double) CLOCKS_PER_SEC;

    cout << "Time of Shuffle : " << duration1 << endl;
    
    
    start2 = std::clock();
    
	
	for (float i = 0.000; i <= 4.000; (i = i + 0.001)) //0.001
	{
    	ifstream oP1(oFile1, ios::in);

    	if (!oP1)
    	{
        	cout << "ERROR!! - FILE CAN NOT OPEN - 5 " << endl;

        	return (-1);
    	}

    	while (getline(oP1, line))
    	{
        	stringstream ss(line);

        	while (getline(ss, word, ';'))
        	{
           	
			   	if (h == 0)
            	{
                	studentNumberTemp = atoi(word.c_str());
            	}

            	else if (h == 1)
            	{
                	classNumberTemp = atoi(word.c_str());
            	}

            	else if (h == 2)
            	{
                	nameTemp = word;
           	 	}

            	else if (h == 3)
            	{
                	surnameTemp = word;
            	}

            	else if (h == 4)
            	{
                	genderTemp = word;
            	}
            	
            	else if (h == 5)
            	{ 		
            		x = word;
            		
            		istringstream iss(word);

                	iss >> ganoTemp2;
            	}
            	
            	else if (h == 6)
            	{
                	sectionSequenceNumberTemp = atoi(word.c_str());
            	}

            	else if (h == 7)
            	{
                	classSequenceNumberTemp = atoi(word.c_str());

                	if ((ganoReady2[p] == x))  //gano sorting
                	{

                    	student[l].studentNumber = studentNumberTemp;
                    	student[l].classNumber = classNumberTemp;
                    	student[l].name = nameTemp;
                    	student[l].surName = surnameTemp;
                    	student[l].gender = genderTemp;
                    	student[l].gano = ganoTemp2;
                    	student[l].sectionSequenceNumber = sectionSequenceNumberTemp;
                    	student[l].classSequenceNumber = classSequenceNumberTemp;
						
						//cout << l << " ---- " << student[l].studentNumber << ";" << student[l].classNumber << ";" << student[l].name << ";" << student[l].surName << ";" << student[l].gender << ";" << fixed << setprecision(3) << student[l].gano << ";" << student[l].sectionSequenceNumber << ";" << student[l].classSequenceNumber << endl;
                    	l++;
                	}

                	h = 0;

                	continue;
            	}

            	h++;
        	}
    	}
    	
    	p++;

    	oP1.close();
    	duration2 = ( std::clock() - start2 ) / (double) CLOCKS_PER_SEC;
	}  

    cout << "Time of sorting Gano : " << fixed << duration2 << endl;

    for (int i = 10000; i > 0; i--)
    {
    	student[t].sectionSequenceNumber = i;
    	t++;
    	//cout << i << "----" << student[i].sectionSequenceNumber << endl;
	}
    
    

    if (!o3)
    {
        cout << "ERROR!! - FILE CAN NOT OPEN 6" << endl;

        return -1;
    }

    else
    {
        for (int i = 0; i < 10000; i++)   // sorting gano
        {
        	//cout << i << " ---- " << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed << setprecision(3) << student[i].gano << ";" << student[i].sectionSequenceNumber << ";" << student[i].classSequenceNumber << endl;

            o3 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name
               << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed
               << setprecision(3) << student[i].gano << ";" << student[i].sectionSequenceNumber << ";" << student[i].classSequenceNumber << endl;
        }
    }

    o3.close();
    
	callGano();
	
	
	int r = 0;
	
    start4 = std::clock();
    
    
    for (int i = 0; i < 1 ; i++)   // sorting gender
    {
    	int eS = 0;
		int kS = 5000;
		
    	ifstream oP5(oFile1, ios::in);
    	
		while ( getline(oP5, line) )
    	{
    		stringstream ss(line);
    		

    		while ( getline(ss, word, ';') )
    		{
    			//cout << "word" << word << endl;

    			if (r == 0)
            	{
                	studentNumberTemp = atoi(word.c_str());
            	}

            	else if (r == 1)
            	{
                	classNumberTemp = atoi(word.c_str());
            	}

            	else if (r == 2)
            	{
                	nameTemp = word;
           	 	}

            	else if (r == 3)
            	{
                	surnameTemp = word;
            	}

            	else if (r == 4)
            	{
                	genderTemp = word;
                	//cout << "gendertemp" << word << endl;

            	}
            	
            	else if (r == 5)
            	{
            		istringstream iss(word);

    				iss >> ganoTemp2;
				}
				
				else if (r == 6)
				{
					
				}
            	

    			else if (r == 7)
    			{
    				
    				back = here(studentNumberTemp);
    		
    				
					if( (genderTemp == "E") && (back == true) )
    				{
	
    					student[eS].studentNumber = studentNumberTemp;
                    	student[eS].classNumber = classNumberTemp;
                    	student[eS].name = nameTemp;
                    	student[eS].surName = surnameTemp;
                    	student[eS].gender = genderTemp;
                    	student[eS].gano = ganoTemp2;
                    	
                    	//cout << eS << " " << student[eS].studentNumber << " " << student[eS].classNumber << " " << student[eS].name << " " << student[eS].surName << " " << student[eS].gender << " " << fixed << setprecision(3) << student[eS].gano << " " << student[eS].sectionSequenceNumber << " " << student[eS].classSequenceNumber << endl;

    					eS++;

    				}
    				
    				else if ( (genderTemp == "K") && (back == true) )
    				{
    					
    					student[kS].studentNumber = studentNumberTemp;
                    	student[kS].classNumber = classNumberTemp;
                    	student[kS].name = nameTemp;
                    	student[kS].surName = surnameTemp;
                    	student[kS].gender = genderTemp;
                    	student[kS].gano = ganoTemp2;
                    	
                    	//cout << kS << " " << genderW[kS].studentNumber << " " << genderW[kS].classNumber << " " << genderW[kS].name << " " << genderW[kS].surName << " " << genderW[kS].gender << " " << fixed << setprecision(3) << genderW[kS].gano << endl;

    					kS++;
					}
    				
    			

    				r = 0;
    				
					continue;

    			}
    			
    			r++;
    		}
    	}

    	oP5.close();
    	
    	
	}
	
    
	
	if (!o5 && !o6)
    {
        cout << "ERROR!! - FILE CAN NOT OPEN 6" << endl;

        return -1;
    }

    else
    {
    	int d, f;
			
			for( int i = 0; i <= 4999; i++)
			{
				d = checkClassNumber(student[i].studentNumber, student[i].classNumber);
    	
    			f = checkSectionNumber(student[i].studentNumber);
    			
    			o5 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name
               		<< ";" << student[i].surName << ";" << student[i].gender << ";" << fixed
               		<< setprecision(3) << student[i].gano << ";" << f << ";" << d <<endl;
    		
			}
			
			for( int m = 5000 ; m <= 9999; m++)
			{
				d = checkClassNumber(student[m].studentNumber, student[m].classNumber);
				
    			f = checkSectionNumber(student[m].studentNumber);
    			
    			o6 << student[m].studentNumber << ";" << student[m].classNumber << ";" << student[m].name
               		<< ";" << student[m].surName << ";" << student[m].gender << ";" << fixed
               		<< setprecision(3) << student[m].gano << ";" << f << ";" << d << endl;
			}
			
			duration4 = ( std::clock() - start4 ) / (double) CLOCKS_PER_SEC;
		}
    
    
        cout << "Time of sorting Gender : " <<  fixed << duration4 << endl;
    
    
    start3 = std::clock();
    
    
    for (int i = 0; i <= 10000 ; i++)  //sorting student number
    {
    	ifstream oP3(oFile1, ios::in);
    	
		while ( getline(oP3, line) )
    	{
    		stringstream ss(line);

    		while ( getline(ss, word, ';') )
    		{

    			if (g == 0)
            	{
                	studentNumberTemp = atoi(word.c_str());
            	}

            	else if (g == 1)
            	{
                	classNumberTemp = atoi(word.c_str());
            	}

            	else if (g == 2)
            	{
                	nameTemp = word;
           	 	}

            	else if (g == 3)
            	{
                	surnameTemp = word;
            	}

            	else if (g == 4)
            	{
                	genderTemp = word;
            	}
            	
            	else if (g == 5)
            	{
            		x = word;
            		
            		istringstream iss(word);

                	iss >> ganoTemp2;
				}
				
				else if (g == 6)
				{
					//sectionSequenceNumberTemp = atoi(word.c_str());
				}

    			else if (g == 7)
    			{
    				
					if( (i == studentNumberTemp ) )
    				{

    					student[v].studentNumber = studentNumberTemp;
                    	student[v].classNumber = classNumberTemp;
                    	student[v].name = nameTemp;
                    	student[v].surName = surnameTemp;
                    	student[v].gender = genderTemp;
                    	student[v].gano = ganoTemp2;
                    	
                    	//cout << v << " " << student[v].studentNumber << " " << student[v].classNumber << " " << student[v].name << " " << student[v].surName << " " << student[v].gender << " " << fixed << setprecision(3) << student[v].gano << endl;

    					v++;

    				}

    				g = 0;
    				
					continue;

    			}
    			
    			g++;
    		}
    	}

    	oP3.close();
    	
    	duration3 = ( std::clock() - start3 ) / (double) CLOCKS_PER_SEC;
	}
	
	    

    cout << "Time of sorting Student Number : " << fixed <<  duration3 << endl;
    
	
	
	if (!o4)
    {
        cout << "ERROR!! - FILE CAN NOT OPEN 6" << endl;

        return -1;
    }

    else
    {
    	int d, f;
    	
        for (int i = 0; i < 10000; i++)   // sorting studentNumber
        {
        	d = checkClassNumber(student[i].studentNumber, student[i].classNumber);
    	
    		f = checkSectionNumber(student[i].studentNumber);
    		
            o4 << student[i].studentNumber << ";" << student[i].classNumber << ";" << student[i].name
               << ";" << student[i].surName << ";" << student[i].gender << ";" << fixed
               << setprecision(3) << student[i].gano << ";" << f << ";" << d << endl;
        }
    }

    o4.close();
    
	
	return 0;
}
