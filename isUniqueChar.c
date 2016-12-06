#include <stdio.h>
#include <string.h>


typedef int bool;
#define false 0
#define true 1

bool isUniqueChar(char str[])
{
	const int MAX = 256;
	int n = strlen(str);
	bool bflag[MAX];
	int i = 0;
	for(; i < MAX; i++)
	{
		bflag[i] = false;
	}
	for(i = 0; i < n; i++)
	{
		if(bflag[str[i]])
			return false;
		bflag[str[i]] = true;
	}
	return true;
}

/*
 * 面试过程中，如果字符串都是a~z的字母，
 * 可以考虑位向量，这样节省内存空间
 *
*/
bool isUniqueChar02(char str[])
{
	int i;
	int n = strlen(str);
	int flag = 0;
	for(i = 0; i < n; i++)
	{
		int pos = str[i] - 'a';
		if( ( flag & (1 << pos) ) > 1)
			return false;
		flag |= (1 << pos);
	}
	return true;
}

int main()
{
	int ret = isUniqueChar02("abcdefghijklmnd");
	printf("%d\n",ret);
	return 0;
}
