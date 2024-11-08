#include<iostream>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

double SetMass(string name);
double GetMass(string s);
double str2dou(string s);

int main()
{
    int num;
    string name;
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> name;
        double mass;
        mass = SetMass(name);
        cout << mass << endl;
    }
    return 0;
}

double SetMass(string formulaa)
{
    int* info;
    info = new int[formulaa.length()];
    //block capitals in English -->5, Lowercase in English-->6, digit-->10~19, Left parenthesis-->21, Left parenthesis-->22
    for(int i=0; i<formulaa.length(); i++){
        if(isupper(formulaa[i])) info[i] = 5;
        else if(islower(formulaa[i])) info[i] = 6;
        else if(isdigit(formulaa[i])){
            info[i] = 10;
            while( (i+1<formulaa.length()) && isdigit(formulaa[i+1]) ){
                info[i+1] = info[i] + 1;
                i++;
            }
        }
        else if(formulaa[i]=='(') info[i] = 21;
        else if(formulaa[i]==')') info[i] = 22;
    }

    string tmp_mole = "";
    string tmp_coef = "";
    double mole_mass = 0;
    double mass = 0;
    string tmp = "";
    int parenthesis = 0;
    for(int i=0; i<formulaa.length(); i++){
        //when info[i]==21("(") && parenthesis==0, judgment would do nothing because no one could more than 21
        if(!parenthesis){ //not have parenthesis
            if( (i+1<formulaa.length()) && (info[i]<info[i+1]) && info[i+1]!=21){
                if( (5<=info[i]) && (info[i]<10) ) tmp_mole += formulaa[i];
                else if( (10<=info[i]) && (info[i]<20) ) tmp_coef += formulaa[i];
            }
            else{
                if(info[i]<10) tmp_mole += formulaa[i];
                else if( (10<=info[i]) && (info[i]<20) ) tmp_coef += formulaa[i];
                mole_mass = GetMass(tmp_mole)*str2dou(tmp_coef);
                cout << "_pre_mole_mass=" << mole_mass << endl;
                cout << "tmp_mole=" << tmp_mole << endl;
                mass += mole_mass;
                tmp_mole = "";
                tmp_coef = "";
                cout << "_pre_mass=" << mass << endl;
            }
        }

        if(parenthesis && info[i]!=22) tmp+=formulaa[i];

        if(info[i]==21) parenthesis++;
        else if(info[i]==22){
            if(parenthesis>1) tmp += formulaa[i];
            //cout << "right parenthesis" << endl;
            parenthesis--;
            if(parenthesis==0){
                cout << "pre_mass=" << mass << endl;
                while( (i+1<formulaa.length()) && (10<=info[i+1]) && (info[i+1]<20) ){
                    i++;
                    tmp_coef += formulaa[i];
                }
                cout << "formulaa_tmp=" << tmp << endl;
                mole_mass = SetMass(tmp)*str2dou(tmp_coef);
                cout << "SetMass(tmp)=" << SetMass(tmp) << endl;
                cout << "mole_mass_parenthesis=" << mole_mass << endl;
                //cout << "pre_mass=" << mass << endl;
                mass += mole_mass;
                cout << "mass="<< mass << endl;
                tmp = "";
                tmp_coef = "";
            }
        }

    }

    delete [] info;

    return mass;
}

double str2dou(string s)
{
    if(s.length()==0) return 1;
    else if(s.length()==1) return static_cast<double>(s[0]-'0');
    else if(s.length()==2) return 10*static_cast<double>(s[0]-'0') + static_cast<double>(s[1]-'0');
    else if(s.length()==3) return 100*static_cast<double>(s[0]-'0') + 10*static_cast<double>(s[1]-'0') + static_cast<double>(s[2]-'0');
}

double GetMass(string s)
{
    if(s=="H") return 1;
    else if(s=="He") return 4;
    else if(s=="Li") return 7;
    else if(s=="Be") return 9;
    else if(s=="B") return 11;
    else if(s=="C") return 12;
    else if(s=="N") return 14;
    else if(s=="O") return 16;
    else if(s=="F") return 19;
    else if(s=="Ne") return 20;
    else if(s=="Na") return 23;
    else if(s=="Mg") return 24;
    else if(s=="Al") return 27;
    else if(s=="Si") return 28;
    else if(s=="P") return 31;
    else if(s=="S") return 32;
    else if(s=="Cl") return 35;
    else if(s=="Ar") return 40;
    else if(s=="K") return 39;
    else if(s=="Ca") return 40;
    else if(s=="Sc") return 45;
    else if(s=="Ti") return 48;
    else if(s=="V") return 51;
    else if(s=="Cr") return 52;
    else if(s=="Mn") return 55;
    else if(s=="Fe") return 56;
    else if(s=="Co") return 59;
    else if(s=="Ni") return 59;
    else if(s=="Cu") return 64;
    else if(s=="Zn") return 65;
    else if(s=="Ga") return 70;
    else if(s=="Ge") return 73;
    else if(s=="As") return 75;
    else if(s=="Se") return 79;
    else if(s=="Br") return 80;
    else if(s=="Kr") return 84;
    else if(s=="Rb") return 85;
    else if(s=="Sr") return 88;
    else if(s=="Y") return 89;
    else if(s=="Zr") return 91;
    else if(s=="Nb") return 93;
    else if(s=="Mo") return 96;
    else if(s=="Tc") return 97;
    else if(s=="Ru") return 101;
    else if(s=="Rh") return 103;
    else if(s=="Pd") return 106;
    else if(s=="Ag") return 108;
    else if(s=="Cd") return 112;
    else if(s=="In") return 115;
    else if(s=="Sn") return 119;
    else if(s=="Sb") return 122;
    else if(s=="Te") return 128;
    else if(s=="I") return 127;
    else if(s=="Xe") return 131;
    else if(s=="Cs") return 133;
    else if(s=="Ba") return 137;
    else if(s=="La") return 139;
    else if(s=="Ce") return 140;
    else if(s=="Pr") return 141;
    else if(s=="Nd") return 144;
    else if(s=="Pm") return 145;
    else if(s=="Sm") return 150;
    else if(s=="Eu") return 152;
    else if(s=="Gd") return 157;
    else if(s=="Tb") return 159;
    else if(s=="Dy") return 163;
    else if(s=="Ho") return 165;
    else if(s=="Er") return 167;
    else if(s=="Tm") return 169;
    else if(s=="Yb") return 173;
    else if(s=="Lu") return 175;
    else if(s=="Hf") return 178;
    else if(s=="Ta") return 181;
    else if(s=="W") return 184;
    else if(s=="Re") return 186;
    else if(s=="Os") return 190;
    else if(s=="Ir") return 192;
    else if(s=="Pt") return 195;
    else if(s=="Au") return 197;
    else if(s=="Hg") return 201;
    else if(s=="Tl") return 204;
    else if(s=="Pb") return 207;
    else if(s=="Bi") return 209;
    else if(s=="Po") return 209;
    else if(s=="At") return 210;
    else if(s=="Rn") return 222;
    else if(s=="Fr") return 223;
    else if(s=="Ra") return 226;
    else if(s=="Ac") return 227;
    else if(s=="Th") return 232;
    else if(s=="Pa") return 231;
    else if(s=="U") return 238;
    else if(s=="Np") return 237;
    else if(s=="Pu") return 244;
    else if(s=="Am") return 243;
    else if(s=="Cm") return 247;
    else if(s=="Bk") return 247;
    else if(s=="Cf") return 251;
    else if(s=="Es") return 252;
    else if(s=="Fm") return 257;
    else if(s=="Md") return 258;
    else if(s=="No") return 259;
    else if(s=="Lr") return 262;
    else if(s=="Rf") return 267;
    else if(s=="Db") return 270;
    else if(s=="Sg") return 269;
    else if(s=="Bh") return 270;
    else if(s=="Hs") return 270;
    else if(s=="Mt") return 278;
    else if(s=="Ds") return 281;
    else if(s=="Rg") return 281;
    else if(s=="Cn") return 285;
    else if(s=="Nh") return 286;
    else if(s=="Fl") return 289;
    else if(s=="Mc") return 289;
    else if(s=="Lv") return 293;
    else if(s=="Ts") return 293;
    else if(s=="Og") return 294;
    else return 0;
}
