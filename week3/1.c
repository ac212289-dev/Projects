#include<stdio.h>
struct student{
    int id;
    float marks;
};

int main()
{   int n;
    printf("Enter the total no. of students :");
    if (scanf("%d",&n)!=1 || n<=0 ||  n>50)
    { 
        printf("ERROR enter valid no.");
      return 1;     
    }  
    struct student s[50];
     for(int i=0;i<n;i++){
        printf("enter the id of %d student\n",i+1);
        if(scanf("%d",&s[i].id)!=1 || s[i].id<=0){
            printf("enter a vaild number");
            return 1;
        }
        printf("enter the marks of student %d\n",i+1);
        if(scanf("%f",&s[i].marks)!=1){
            printf("enter valid marks");
            return 1;
        } 
    }
    for (int i=0;i<n;i++){
    printf("the marks of the student with %d id are %f ",s[i].id,s[i].marks);
    printf("\n");
}
    
    return 0;

}