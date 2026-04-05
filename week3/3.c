#include<stdio.h>
struct student {
    int id ;
    float marks;
    char grade;
} ;
void assign_grade(struct student a[],int n )
{    for(int i=0;i<n;i++){
    if(a[i].marks>=90 && a[i].marks<=100){
    a[i].grade='A';}
    else if (a[i].marks>=80){
    a[i].grade='B';}
    else if(a[i].marks>=60){
    a[i].grade='C';}
    else if (a[i].marks>=40){
    a[i].grade='D';}
    else{
    a[i].grade='F';}
}}
void max_marks(struct student a[],int n)
{ int max =0;
    for(int i=0;i<n;i++)
    {  if (a[i].marks>a[max].marks)
        {max =i;
          }  }
        printf("The max marks are %.2f ,out of all %d students\n",a[max].marks,n);
    
}
int main()
{
     int n;
      printf("enter the total number of students : ");
       if  (scanf("%d",&n)!=1 || n>5){
        printf("Enter a valid number and it should be below or equal to 5\n");
        return 1;
       }
        struct student data[5];
        struct student *ptr=data;
    
        for (int i=0;i<n;i++){
        struct student *a=&ptr[i]; 
            printf("enter the ID of student %d : ",i+1);
            if (scanf("%d",&a->id)!=1 || a->id <= 0){
                printf("enter a valid ID");
                return 1;
            } 
        printf("Enter the marks  of student %d : ",i+1);
        if(scanf("%f",&a->marks)!=1 || a->marks <=0  || a->marks>=100){
            printf("enter valid marks Between 0-100\n");
            return 1;
        } }
        assign_grade(data,n);
        printf(" the data of students is below ");
        for (int i=0;i<n;i++)
        {
            printf("ID : %d\n",ptr[i].id);
            printf("Marks : %.2f\n",ptr[i].marks);
            printf("Grade : %c\n",ptr[i].grade);
      }
        max_marks(data,n);

return 0;
        
}