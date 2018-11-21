#include<iostream>
using namespace std;
class DNA{
	friend int hamming(DNA const &, DNA const &);
	public:
		DNA(string dna_string);
		string get_dna() const{	return dna_string;}
		string get_rna() const{	return rna_string;}
		string get_rc() const{	return reverse_complement_string;}
		string get_protein() const{	return protein_sequence;}
		long double gc_content();
		
	private:
		void count();
		void reverse_complement();
		void transcribe();
		void translate();
		
		string dna_string;
		string rna_string;
		string reverse_complement_string;
		string protein_sequence;
		int a,c,g,t;
};

DNA::DNA(string dna_string){
	this->dna_string = dna_string;
	count();
	reverse_complement();
	transcribe();
	translate();
}

//Count occurences of A,C,G, and T base in a DNA string
void DNA::count(){
	a=0,c=0,g=0,t=0;
	for(int i=0;i<dna_string.length();i++){
		if(dna_string[i]=='A')		a++;
		else if(dna_string[i]=='C')	c++;
		else if(dna_string[i]=='G')	g++;
		else if(dna_string[i]=='T')	t++;
	}
}

//Transcribe DNA into mRNA
void DNA::transcribe(){
	for(int i=0;i<dna_string.length();i++){
		if(dna_string[i]=='A')		dna_string[i]='U';
		else if(dna_string[i]=='C')	dna_string[i]='G';
		else if(dna_string[i]=='G')	dna_string[i]='C';
		else if(dna_string[i]=='T')	dna_string[i]='A';
	}
}

//reverse-complement of a DNA string is reversed
// and every nucleotide replaced with its complement
void DNA::reverse_complement(){
	for(int i=dna_string.length()-1;i>=0;i--){
		if(dna_string[i]=='A')		reverse_complement_string+='T';
		else if(dna_string[i]=='C')	reverse_complement_string+='G';
		else if(dna_string[i]=='G')	reverse_complement_string+='C';
		else if(dna_string[i]=='T')	reverse_complement_string+='A';
	}
}

//GC-content of DNA strings
long double DNA::gc_content(){
	long double count=c+g, length=dna_string.length();
	count*=100;
	if(length)	count/=length;
	return count;
}

//mRNA to Protein translation
void DNA::translate(){
	bool stop = false;	string rna;
	for(int i=0;i<rna_string.length() && !stop;i+=3){
		rna= rna_string.substr(i,3);
		switch(rna[0]){
			case 'U':
				switch(rna[1]){
					case 'U':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="F";
								break;
							case 'A':
							case 'G':
								protein_sequence+="L";
								break;
						}
						break;
					case 'C':
						protein_sequence+="S";
						break;
					case 'A':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="Y";
								break;
							case 'A':
							case 'G':
								stop=1;
								break;
						}
						break;
					case 'G':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="C";
								break;
							case 'A':
								stop=1;
								break;
							case 'G':
								protein_sequence+="W";
								break;
						}
						break;
				}
				break;
				
				case 'C':
				switch(rna[1]){
					case 'U':
						protein_sequence+="L";
						break;
					case 'C':
						protein_sequence+="P";
						break;
					case 'A':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="H";
								break;
							case 'A':
							case 'G':
								protein_sequence+="Q";
								break;
						}
						break;
					case 'G':
						protein_sequence+="R";
						break;
				}
				break;
				
				case 'A':
				switch(rna[1]){
					case 'U':
						switch(rna[2]){
							case 'U':
							case 'C':
							case 'A':
								protein_sequence+="I";
								break;
							case 'G':
								protein_sequence+="M";
								break;
						}
						break;
					case 'C':
						protein_sequence+="T";
						break;
					case 'A':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="N";
								break;
							case 'A':
							case 'G':
								protein_sequence+="K";
								break;
						}
						break;
					case 'G':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="S";
								break;
							case 'A':
							case 'G':
								protein_sequence+="R";
								break;
						}
						break;
				}
				break;
				
				case 'G':
				switch(rna[1]){
					case 'U':
						protein_sequence+="V";
						break;
					case 'C':
						protein_sequence+="A";
						break;
					case 'A':
						switch(rna[2]){
							case 'U':
							case 'C':
								protein_sequence+="D";
								break;
							case 'A':
							case 'G':
								protein_sequence+="E";
								break;
						}
						break;
					case 'G':
						protein_sequence+="G";
						break;
				}
				break;
		}
	}
}

//Hamming distance between two equal strings
int hamming(DNA const &dna_1, DNA const &dna_2){
	int distance = 0;
	for(int i=0;i<dna_1.dna_string.length();i++){
		if(dna_1.dna_string[i] != dna_2.dna_string[i])	distance++;
	}
	return distance;
}

/*Copyrights reserved*/
