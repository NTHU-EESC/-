#include <iostream>
#include <string>
using namespace std;

class Reg
{
public:
        Reg(string name_in);
        string name;
        int cnt=0;
};

int main(){

        Reg zero("zero");
		Reg ra("ra");
		Reg sp("sp");
		Reg gp("gp");
		Reg tp("tp");
		Reg fp("fp");
		Reg t0("t0");
		Reg t1("t1");
		Reg t2("t2");
		Reg t3("t3");
		Reg t4("t4");
		Reg t5("t5");
		Reg t6("t6");
		Reg a0("a0");
		Reg a1("a1");
		Reg a2("a2");
		Reg a3("a3");
		Reg a4("a4");
		Reg a5("a5");
		Reg a6("a6");
		Reg a7("a7");
		Reg s0("s0");
		Reg s1("s1");
		Reg s2("s2");
		Reg s3("s3");
		Reg s4("s4");
		Reg s5("s5");
		Reg s6("s6");
		Reg s7("s7");
		Reg s8("s8");
		Reg s9("s9");
		Reg s10("s10");
		Reg s11("s11");

		char c3;
		char c2='x';
        char c1='x';
        char c0='x';
        while(cin>>c3){
            if(c0=='z' && c1=='e' && c2=='r' && c3=='o') zero.cnt++;
			if(c0=='r' && c1=='a') ra.cnt++;
			if(c0=='s' && c1=='p') sp.cnt++;
			if(c0=='g' && c1=='p') gp.cnt++;
			if(c0=='t' && c1=='p') tp.cnt++;
			if(c0=='f' && c1=='p') fp.cnt++;
			if(c0=='t' && c1=='0') t0.cnt++;
			if(c0=='t' && c1=='1') t1.cnt++;
			if(c0=='t' && c1=='2') t2.cnt++;
			if(c0=='t' && c1=='3') t3.cnt++;
			if(c0=='t' && c1=='4') t4.cnt++;
			if(c0=='t' && c1=='5') t5.cnt++;
			if(c0=='t' && c1=='6') t6.cnt++;
			if(c0=='a' && c1=='0') a0.cnt++;
			if(c0=='a' && c1=='1') a1.cnt++;
			if(c0=='a' && c1=='2') a2.cnt++;
			if(c0=='a' && c1=='3') a3.cnt++;
			if(c0=='a' && c1=='4') a4.cnt++;
			if(c0=='a' && c1=='5') a5.cnt++;
			if(c0=='a' && c1=='6') a6.cnt++;
			if(c0=='a' && c1=='7') a7.cnt++;
			if(c0=='s' && c1=='0') s0.cnt++;
			if(c0=='s' && c1=='1' && c2!='0' && c2!='1') s1.cnt++;
			if(c0=='s' && c1=='2') s2.cnt++;
			if(c0=='s' && c1=='3') s3.cnt++;
			if(c0=='s' && c1=='4') s4.cnt++;
			if(c0=='s' && c1=='5') s5.cnt++;
			if(c0=='s' && c1=='6') s6.cnt++;
			if(c0=='s' && c1=='7') s7.cnt++;
			if(c0=='s' && c1=='8') s8.cnt++;
			if(c0=='s' && c1=='9') s9.cnt++;
			if(c0=='s' && c1=='1' && c2=='0') s10.cnt++;
			if(c0=='s' && c1=='1' && c2=='1') s11.cnt++;
            c0=c1;
			c1=c2;
			c2=c3;
        }

		cout << "REG: " << "zero" << ", count= " << zero.cnt << endl;
		cout << "REG: " << "ra" << ", count= " << ra.cnt << endl;
		cout << "REG: " << "sp" << ", count= " << sp.cnt << endl;
		cout << "REG: " << "gp" << ", count= " << gp.cnt << endl;
		cout << "REG: " << "tp" << ", count= " << tp.cnt << endl;
		cout << "REG: " << "fp" << ", count= " << fp.cnt << endl;
		cout << "REG: " << "t0" << ", count= " << t0.cnt << endl;
		cout << "REG: " << "t1" << ", count= " << t1.cnt << endl;
		cout << "REG: " << "t2" << ", count= " << t2.cnt << endl;
		cout << "REG: " << "t3" << ", count= " << t3.cnt << endl;
		cout << "REG: " << "t4" << ", count= " << t4.cnt << endl;
		cout << "REG: " << "t5" << ", count= " << t5.cnt << endl;
		cout << "REG: " << "t6" << ", count= " << t6.cnt << endl;
		cout << "REG: " << "a0" << ", count= " << a0.cnt << endl;
		cout << "REG: " << "a1" << ", count= " << a1.cnt << endl;
		cout << "REG: " << "a2" << ", count= " << a2.cnt << endl;
		cout << "REG: " << "a3" << ", count= " << a3.cnt << endl;
		cout << "REG: " << "a4" << ", count= " << a4.cnt << endl;
		cout << "REG: " << "a5" << ", count= " << a5.cnt << endl;
		cout << "REG: " << "a6" << ", count= " << a6.cnt << endl;
		cout << "REG: " << "a7" << ", count= " << a7.cnt << endl;
		cout << "REG: " << "s0" << ", count= " << s0.cnt << endl;
		cout << "REG: " << "s1" << ", count= " << s1.cnt << endl;
		cout << "REG: " << "s2" << ", count= " << s2.cnt << endl;
		cout << "REG: " << "s3" << ", count= " << s3.cnt << endl;
		cout << "REG: " << "s4" << ", count= " << s4.cnt << endl;
		cout << "REG: " << "s5" << ", count= " << s5.cnt << endl;
		cout << "REG: " << "s6" << ", count= " << s6.cnt << endl;
		cout << "REG: " << "s7" << ", count= " << s7.cnt << endl;
		cout << "REG: " << "s8" << ", count= " << s8.cnt << endl;
		cout << "REG: " << "s9" << ", count= " << s9.cnt << endl;
		cout << "REG: " << "s10" << ", count= " << s10.cnt << endl;
		cout << "REG: " << "s11" << ", count= " << s11.cnt << endl;




        return 0;
}

Reg::Reg(string name_in)
{
        name=name_in;
}

