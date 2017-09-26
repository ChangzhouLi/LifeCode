class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL)return;
		int l1 = length;
        for(int i = 0; i < length; i++)if(str[i] == ' ')l1 += 2;
        char* p1 = str + length;
        char* p2 = str + l1;
        while(p1 < p2){
            if(*p1 != ' '){
                *p2-- = *p1;
            }else{
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            }
            p1--;
        }
	}
};
