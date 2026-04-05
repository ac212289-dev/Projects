// pointer to structure
#include<stdio.h>
struct student{
    int id;
    float marks;
};

int main()
{   
    int n;
    printf("Enter the total no. of students :");
    if (scanf("%d",&n)!=1 || n<=0 ||  n>50)           // validation check for input
    { 
        printf("ERROR enter valid no.");
      return 1;     
    }  
    struct student s[50];
    struct student *ptr=s;        // pointer to  structure s

     for(int i=0;i<n;i++){
        struct student *curr =&ptr[i];                         // assigned a new pointer curr fro ptr[i] , ptr[i] is for the structure
        printf("enter the id of %d student\n",i+1);
        if(scanf("%d",&curr->id)!=1 || curr->id<=0){      // validation check for input
            printf("enter a vaild number");
            return 1;
        }
        printf("enter the marks of student %d\n",i+1);
        if(scanf("%f",&curr->marks)!=1 || curr->marks>100 || curr->marks<0){      
            printf("enter valid marks");
            return 1;
        } 
    }
    for (int i=0;i<n;i++){
    printf("the marks of the student with %d id are %.2f ",ptr[i].id,ptr[i].marks); // print the value stored in thes structure 
    printf("\n");
}
    
    return 0;

}