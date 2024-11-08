#include <stdio.h>
#include <ctype.h>

int main(void){
	char text[1000];
	char temp;
	int n_alpha[26] = {0};
	int text_length, *max, shift;
	int i;
	
	i = 0;								//本機測試用 
	while((temp = getchar()) != '.'){
		text[i] = temp;
		i++;
	}
	text[i] = temp;
	text_length = i+1;
	
	/*i = 0;							//oj 型式 
	while((temp = getchar()) != EOF){
		text[i] = temp;
		i++;
	}
	text_length = i;*/
	
	for(i=0;i<text_length;i++){
		if(islower(text[i]))
			n_alpha[text[i]-'a']++;
		else if(isupper(text[i]))
			n_alpha[text[i]-'A']++;
	}
	
	max = &n_alpha[0];
	//max_alpha = 0;
	for(i=1;i<26;i++){
		if(*max < n_alpha[i]){
			max = &n_alpha[i];
		//	max_alpha = i;
		}
	}
	shift = max-&n_alpha[4];//偏移 
//	 	= max_alpha - 4
/*   a[i]  <--->  *(a+i)   //等價寫法 
             &a[i] <--->  (a+i)   */
	
	for(i=0;i<text_length;i++){//轉換 
		if(islower(text[i]))
			printf("%c", (text[i]-'a'-shift)%26+'a');
		else if(isupper(text[i]))
			printf("%c", (text[i]-'A'-shift)%26+'A');
		else
			printf("%c", text[i]);
	}
	return 0;
}
