#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int score;
	int i=0;
	char ch;
		
	printf("5PPJJY77777!!~!!!!!YY?5555PPP5?J55Y5YY5YYYJ^JGPPP5\n"); //螢幕上出現個人風格的畫面
    printf("5PG?Y5YYY55YJJYY555YJ?J???JJYJ??JJJ????????^5PPPPP\n");
    printf("55GY5555PGBBBBBBBBBP??7777?JJJ??J??????????75P55JY\n");
    printf("YPJ?55Y55GGGGBBBBBBP?777777??J???777?7????7J555J7Y\n");
    printf("Y5JY5YYY5PGGGGBBGBBP?7YPJ?7?JYY?77!!7777777?555JJ5\n");
    printf("YYYYYYYYJYPGGGGBBBBG5PB###BGB#BGPYJ?7777777?555555\n");
    printf("YYYYYJYJJYPGB##B#########&&&#&####BGGPY?777755555Y\n");
    printf("YJJJ??JYPGB#&&&#&#&&&&&&&&&&&&#####B###B5?77??7777\n");
    printf("???7?5B##&##&&##&&&&&&&&&&&&&&#######BBBGG5JJYYY55\n");
    printf("777?P#&&&&&##&&#&&&#&&&&&&&&#&##B##B##BBBBBBGGPPPP\n");
    printf("???G###&&#######&&&#&&&&&&&&&##BB##B#BBBBBBBBBGPPP\n");
    printf("~!J########BPYYG#&######B#####BBB#BBBGGBGJPGBGGPPP\n");
    printf(".~G#&##&#P?J55?JB#BBBBBGGBBBBBBBBBBBBBBB5!?BGGGGP5\n");
    printf(":!BB#####Y7JY?P#BBBBBBBGBBB###BBBBGGGGB#Y!!PBBGGGP\n");
    printf(":7B#####BPGBBB##BBBBBBGBB#&####BBBBGGBB##Y?Y###GPP\n");
    printf(":Y#######&#B#BPPPPY??77YYYYJ?5GGGGB#BGGGGGG&&#BG5Y\n");
    printf(" ~G#####&#55PP5PP5!!7!7J7JGP!:?GGBGYYP5!^~7?G#PYYY\n");
    printf(".:5#####B5JPG5P55YJYBPPBGGBB?^?Y5#P5P##?~!!7JBG5YY\n");
    printf("^~JB#B##BP5YYJ?JYPP5PJG&#&&&BYY!!G&#&&&BY????G#B5Y\n");
    printf("^^^J5P5B#5YYY55Y5PBGPPP#BGB#PY?~^7PBB&&@BJJJYGBP5Y\n");
    printf("~~~~?5YGBYJJJJ5555Y5YPP55PPPJ?!!~^!YGGB#5YY5PBP~7!\n");
    printf("!!!!!YPGGYJJJ??YYPPPPPP5555YJ?7!^^^!5PGPY5PGGY!^~!\n");
    printf("!!!!!?YYP5YYJJJ??YYYYYYYJYYJ?JYJ???77JJY555J~^~~~!\n");
    printf("!!!!!!7JY5YJJJJ???J?JJ??7?Y5PGGGGGG5?7!7???!~~~7!7\n");
    printf("!!!!!!~!7YYJJJ?J?JJJ??7!!7????JYYJJ?!7?JJJ?~~7??Y7\n");
    printf("JJJJJ??JYYYYJJJ?JJ???7?J????JJJ?77??7??JJ?~~~!~!?!\n");
    printf("J?7??J77J??YYJJJJJ???JPGGGGGGGGPPGGGP5J??!:^7!: .^\n");
    printf("~~^~~?!^~!!7JYJJJJ?JJJJJYY55YYYYJYYYYYJ?~~^.~?~..^\n");
    printf("^~!~~!?~~!!~~JYYYYJYYJ????JY555555J?JJ?!!!!.^7~:.:\n");
    printf("~^^!~~J7~!~^^J5555YJYJJ??7??????7????!:^!?7.:7~^.:\n");
    printf("!^^~~!?J~~~^^J555555YYJJ?J??7?!77??7~~::~J?::!~^::\n");
    printf("7^^!~^!J7~~^^?5555PPPPP555YYYYYYY?!::~^:~JY!^~^:::\n");
    printf("7^~!~^^7?~~^^~5P5PPPPGGGGGGGGGPG~.:::~~:^?Y?~^^:::\n");
    printf("7~!!~^^~7!^~^^?GGPPPPGGGGGGGGGGJ..^::~!:^7YJ!^:::^\n");
    printf("!!!~~^^^~7~^~~~JGGGGGGGGGGGGGP?:::^::~!^^7YY!^^~~~\n");
    printf("!!!~~~^^~~!~~~~~75PPGGGGGGGPY!^::^^^:~!^^7YY7^^!~!\n");
    printf("~~!!!~^^~~~!~~~~~!JY55555Y?!~^::^^^^^!!^^?YY7::~!!\n");
    printf("^~~!!~~~^!~~~~~~~~!7???77!~^:::::^~^^!!^~?YJ!^:~!!\n");
    printf("^~~!!~~~^~?~~~~^^~~!!!!~^::.....:~~^^!!^~?JJ!^^~!!\n");
    printf("^^~!!~~~~^7J!~~~^^^~~^^:......:^~~~^^~~~~?J?!^^~7!\n");
    printf("^^~~~~~~~~~??77!!~~~^^::::.:^~!!!~^:^^!!~7?7~^^!?7\n");
	
	while (i<3)
	{
		printf("Give Me Four Number:"); 
		scanf("%d",&score);
		i++;
		
		if (score==2024)
		{
			printf("Welcome \n");
			printf("------------------------------\n");
      	    printf("|  �A a.  畫出直角三角形     |\n");
        	printf("|     b.  顯示乘法表         |\n");
        	printf("|     c.  結束               |\n");
        	printf("------------------------------\n");
			scanf("%c",&ch);
			if (ch==65 || ch==97)
			{
				system("cls");  // 清除螢幕
				printf("Please Enter 'a' To 'n' \n");
				fflush(stdin);
			}
			else if(ch==97 || ch==122)  
   			{
        		printf("Lowercase"); 
    		}
    		fflush(stdin);
		}
	
		else if(i==3)
		{
			printf("%c", '\a');
		}
	}
	
	return 0;
}
