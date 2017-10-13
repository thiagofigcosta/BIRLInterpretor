#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <time.h>

using namespace std;

struct BIRL_SYNTAX{
	BIRL_SYNTAX(string birl,string c){
		BIRL=birl;
		C=c;
	}
	BIRL_SYNTAX(string birl,string c,string extra){
		BIRL=birl;
		C=c;
		C_extra=extra;
	}
	BIRL_SYNTAX(string birl,string c,string extra,bool rmpar){
		BIRL=birl;
		C=c;
		C_extra=extra;
		removePar=rmpar;
	}
	string BIRL;
	string C;
	string C_extra="";
	bool removePar=false;
};


void HORADOSHOWPORRA(string TRINTAESETEANO,string VEMMOSNTRO){
	FILE *in;
    char buff[512];
    if(!(in = popen((char*)("gcc "+TRINTAESETEANO+" -o "+VEMMOSNTRO).c_str(), (char*)"r"))){
        exit(1);
    }
    bool msg=false;
    while(fgets(buff, sizeof(buff), in)!=NULL){
    	if(!msg){
    		cout<<"CODEI PRA CARALHO MAS NÃO COMPILOU!\n";
    		msg=true;
    	}
        cout << buff;
    }
    pclose(in);
    system(("./"+VEMMOSNTRO).c_str());
    system(("rm -f "+TRINTAESETEANO+" "+VEMMOSNTRO).c_str());
}

bool isntStringBetween(string str, int s, int size){
	int str_founded=-1;
	int e=s+size;
	for(int i=0;i<str.size();i++){
		if(str[i]=='\"'){
			if(str_founded<0)
				str_founded=i;
			else{
				if(str_founded<=s&&i>=e)
					return true;
				str_founded=-1;
			}
		}
	}
	return false;
}

void replaceAllExceptStrs(string &s,const string &search,const string &replace){
    for(size_t pos=0;;){
        pos=s.find(search,pos);
        if(pos==string::npos) break;
        if(!isntStringBetween(s,static_cast<int>(pos),search.size())){
        	s.erase(pos,search.length());
        	s.insert(pos,replace);
        	pos+=replace.length();
        }else{
        	pos+=search.length();
        }
    }
}
void replaceDoubleAllExceptStrs(string &s,const string &search,const string &replace,const string &replace2,bool rm){
    for(size_t pos=0;;){
        pos=s.find(search,pos);
        if(pos==string::npos) break;
        if(!isntStringBetween(s,static_cast<int>(pos),search.size())){
        	s.erase(pos,search.length());
        	s.insert(pos,replace);
        	pos+=replace.length();
        	stack<void*> par;
        	for(int i=static_cast<int>(pos);i<s.size();i++){
        		if(s[i]=='('){
        			par.push(nullptr);
        		}else if(s[i]==')'){
        			par.pop();
        			if(par.empty()){
        				if(rm){
	        				s.erase(pos+1,1);
	        				s.erase(i-1,1);
	        				s.insert(i-1,replace2);
	        			}else{
	        				s.insert(i+1,replace2);
	        			}
        				break;
        			}
        		}
        	}
        }else{
        	pos+=search.length();
        }
    }
}

string BODYBUILDER(int len) {
    static const string alphanum="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string out="";
    for(int i=0;i<len;i++){
        out+=alphanum[rand()%alphanum.size()];
    }
    return out;
}

void replaceAll(string &s,const string &search,const string &replace){
    for(size_t pos=0;;pos+=replace.length()){
        pos=s.find(search,pos);
        if(pos==string::npos) break;
        s.erase(pos,search.length());
        s.insert(pos,replace);
    }
}

void BIRLLLLLLLLLLLL(vector<string> &birl,const vector<BIRL_SYNTAX> &ESTEROIDES){
	for(int i=0;i<birl.size();i++){
		replaceAll(birl[i],"Ã","A");
		replaceAll(birl[i],"Í","I");
		replaceAll(birl[i],"É","E");
		for(int j=0;j<ESTEROIDES.size();j++){
			if(ESTEROIDES[j].C_extra!=""){
				replaceDoubleAllExceptStrs(birl[i],ESTEROIDES[j].BIRL,ESTEROIDES[j].C,ESTEROIDES[j].C_extra,ESTEROIDES[j].removePar);
			}else{
				replaceAllExceptStrs(birl[i],ESTEROIDES[j].BIRL,ESTEROIDES[j].C);
			}
		}
	}
	birl.insert(birl.begin(),"#include <stdio.h>\n#include <math.h>\n\n");
}

void MALHAR_BIRLLLLLL(vector<BIRL_SYNTAX> &ESTEROIDES){
	ESTEROIDES.push_back(BIRL_SYNTAX("HORA DO SHOW","int main (void) {"));
	ESTEROIDES.push_back(BIRL_SYNTAX("BIRL","}"));
	ESTEROIDES.push_back(BIRL_SYNTAX("CE QUER VER ESSA PORRA?","printf"));
	ESTEROIDES.push_back(BIRL_SYNTAX("QUE QUE CE QUER MONSTRAO?","scanf"));
	ESTEROIDES.push_back(BIRL_SYNTAX("ELE QUE A GENTE QUER?","if","{"));
	ESTEROIDES.push_back(BIRL_SYNTAX("NAO VAI DAR NAO","} else {"));
	ESTEROIDES.push_back(BIRL_SYNTAX("QUE NUM VAI DAR O QUE?","} else if ","{"));
	ESTEROIDES.push_back(BIRL_SYNTAX("NEGATIVA BAMBAM","while ","{"));
	ESTEROIDES.push_back(BIRL_SYNTAX("MAIS QUERO MAIS","for ","{"));
	ESTEROIDES.push_back(BIRL_SYNTAX("OH O HOME AI PO"," ","{",true));
	ESTEROIDES.push_back(BIRL_SYNTAX("OH O HOMEM AI PO"," ","{",true));
	ESTEROIDES.push_back(BIRL_SYNTAX("O O HOME AI PO"," ","{",true));
	ESTEROIDES.push_back(BIRL_SYNTAX("O O HOMEM AI PO"," ","{",true));
	ESTEROIDES.push_back(BIRL_SYNTAX("BORA CUMPADE","return"));
	ESTEROIDES.push_back(BIRL_SYNTAX("BORA CUMPADI","return"));
	ESTEROIDES.push_back(BIRL_SYNTAX("AJUDA O MALUCO TA DOENTE"," "));
	ESTEROIDES.push_back(BIRL_SYNTAX("AJUDA O MALUCO QUE TA DOENTE"," "));
	ESTEROIDES.push_back(BIRL_SYNTAX("SAI FILHO DA PUTA","break"));
	ESTEROIDES.push_back(BIRL_SYNTAX("SAI FILHA DA PUTA","break"));
	ESTEROIDES.push_back(BIRL_SYNTAX("VAMO MONSTRO","continue"));

	ESTEROIDES.push_back(BIRL_SYNTAX("FRANGO","char"));
	ESTEROIDES.push_back(BIRL_SYNTAX("MONSTRO","int"));
	ESTEROIDES.push_back(BIRL_SYNTAX("MONSTRINHO","short"));
	ESTEROIDES.push_back(BIRL_SYNTAX("MONSTRAO","long"));
	ESTEROIDES.push_back(BIRL_SYNTAX("TRAPEZIO DESCENDENTE","double"));
	ESTEROIDES.push_back(BIRL_SYNTAX("TRAPEZIO","float"));
	ESTEROIDES.push_back(BIRL_SYNTAX("BICEPS","unsigned"));
}

int main(int argc, char** argv){
	if(argc!=2){
        printf("ASSIM QUE USA SA PORRA: %s [ARQUIVO BIRLLLLLLLLLLLL]\n", argv[0]);
        return 1;
    }
    srand(time(NULL));
    vector<string> birllllllllllll;
    ifstream PROTEIIINA(argv[1]);
	if(PROTEIIINA.is_open()){
		birllllllllllll.resize(1);
		for(int i=0;getline(PROTEIIINA,birllllllllllll[i]);i++)
			birllllllllllll.push_back("");
		birllllllllllll.pop_back();
		PROTEIIINA.close();
	}else{
		printf("CADE O ARQUIVO MONSTRO, NA1 ACHEI\n");
		return 1;
	}
	vector<BIRL_SYNTAX> WHEY;
	MALHAR_BIRLLLLLL(WHEY);
	BIRLLLLLLLLLLLL(birllllllllllll,WHEY);
	string SHAPEE=BODYBUILDER(15)+".c";
	ofstream MUSCULOS(SHAPEE);
	for(string fibra:birllllllllllll)
		MUSCULOS<<fibra<<endl;
	MUSCULOS.close();
	HORADOSHOWPORRA(SHAPEE,BODYBUILDER(15));
}