#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(int argc,char *argv[]){
	
    pid_t pid;
    char *message;
    int exit_code;
    
    char *bin;
    
    char *call = argv[1];
    
    if(strcmp(call,"pga") == 0){
        bin = "/Applications/PostgreSQL\\ 9.4/pgAdmin\\ III.app/Contents/MacOS/applet";
        message = "pgAdmin III";
    }
    
    else if(strcmp(call,"qq") == 0)
    {
        bin = "nohup /Applications/QQ.app/Contents/MacOS/QQ > /dev/null &";
        message = "QQ";
    }
    
    else if(strcmp(call,"ps") == 0)
    {
        bin = "nohup /Applications/PhpStorm.app/Contents/MacOS/phpstorm > /dev/null &";
        message = "PhpStorm";
    }
    
    else{
        printf("no bin defined\r\n");
        exit(0);
    }
    
    printf("Starting...\r\n");
    pid = fork();
    
    switch (pid) {
        case -1:
            perror("fork failed");
            exit(0);
            
        case 0:
            system(bin);
            exit_code = 37;
            break;
        
        default:
            exit_code = 0;
            break;
    }
    
    if(pid != 0){
        int stat_val;
        pid_t child_pid;
        
        child_pid = wait(&stat_val);
        
        if(WIFEXITED(stat_val))
            printf("%s is started\r\n",message);
    }
    
	exit(exit_code);
}
