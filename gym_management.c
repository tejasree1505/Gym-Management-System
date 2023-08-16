#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>                   
                    

COORD coord = {0, 0};
char *filename="gymdata.txt";
int remove_id;



void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* Structure to store gym member details */
typedef struct member{
    int member_id;
    char name[1000];
    char address[100];
    char contact[10];
    char dob[10];
    char membersince[20];
    int msdays;
    char end_date[20];
    float height;
    float weight;
    int workout_type;
    int diet_type;
}member;

 typedef struct node {
    member data;           
    struct node *next; 
} NODE;

NODE *head=NULL;

static int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int day, month, year;

unsigned short day_counter;

void dietplan1(int pos){
            printf("Meats, poultry, and fish: Sirloin steak, ground beef, pork tenderloin, venison, chicken breast, salmon, tilapia, and cod.");
            gotoxy(20,pos+=1);
            printf("Dairy: Yogurt, cottage cheese, low fat milk, and cheese.");
            gotoxy(20,pos+=1);
            printf("Grains: Bread, cereal, crackers, oatmeal, quinoa, popcorn, and rice.");
            
}

void dietplan2(int pos){
    printf("Early morning---10 Spirulina or green leafy veggie juice + 1 fruit of your choice");
            gotoxy(20,pos+=1);
            printf("Breakfast---1 bowl vegetable sprout poha with chutney / 3-4 dal paddu with sambhar / 2 oats idli + sambhar");
            gotoxy(20,pos+=1);
            printf("Lunch---2 multigrain roti + 1 bowl veg or non-veg (seafood, fish, chicken) subji of choice + 1 bowl of thick dal");
            gotoxy(20,pos+=1);
            printf("Dinner---1 bowl fruit and veggie mixed salad of choice + 2 bran rotis (wheat roti or oat bran) + 1 bowl of non-veg subji ");

}

void workout1(int pos){
    
    printf("Wide grip pull-down---3 sets of 12 reps");
     gotoxy(20,pos+=1);
    printf("Deadlift---3 sets of 12 reps");
     gotoxy(20,pos+=1);
    printf("Incline press---3 sets of 12 reps");
     gotoxy(20,pos+=1);
}
void workout2(int pos){
    printf("Jumping jacks");
     gotoxy(20,pos+=1);
    printf("Squat jumps");
     gotoxy(20,pos+=1);
    printf("Treadmill");
     gotoxy(20,pos+=1);
   
}
int is_leap(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

void next_day()
{
    day += 1; day_counter++;
    if (day > days_in_month[month]) {
        day = 1;
        month += 1;
        if (month > 12) {
            month = 1;
            year += 1;
            if (is_leap(year)) {
                days_in_month[2] = 29;
            } else {
                days_in_month[2] = 28;
            }
        }
    }
}

void set_date(int d, int m, int y) 
{
    m < 1 ? m = 1 : 0;
    m > 12 ? m = 12 : 0;
    d < 1 ? d = 1 : 0;
    d > days_in_month[m] ? d = days_in_month[m] : 0;
    if (is_leap(y)){
        days_in_month[2] = 29;
    } 
    else {
        days_in_month[2] = 28;
    }
    day = d;
    month = m;
    year = y;
}

void skip_days(int x)
{
    int i;
    for (i=0;i<x;i++) next_day();
}



float bmicalc(float weight, float height){
    return (weight/(height*height));
}

void addmember(void) {

    
    system("cls");
    int pos =3;
    gotoxy(20,pos+=2);
    printf("---------------NEW MEMBER---------------");
    NODE *p = malloc(sizeof(NODE));
    
    gotoxy(20,pos+=2);
    printf("Member ID: ");
    scanf("%d",&p->data.member_id);
    gotoxy(20,pos+=2);
    printf("Name: ");
    scanf("%s",p->data.name);
    gotoxy(20,pos+=2);
    printf("Address: ");
    scanf("%s",p->data.address);
    gotoxy(20,pos+=2);
    printf("Contact Number: ");
    scanf("%s",p->data.contact);
    gotoxy(20,pos+=2);
    printf("DOB: ");
    scanf("%s",p->data.dob);
    gotoxy(20,pos+=2);
    printf("Member Since: ");
    
    int day1, month1, year1;
    char str_day[10],str_month[10],str_year[10],date[100],end_date[20];
    scanf("%d-%d-%d",&day1,&month1,&year1);
    sprintf(str_day,"%d",day1); //to convert int to string
    sprintf(str_month,"%d",month1); 
    sprintf(str_year,"%d",year1); 
    strcpy(date,"");
   
    strcat(date,str_day);
    strcat(date," - ");
    strcat(date,str_month);
    strcat(date," - ");
    strcat(date,str_year);
    strcpy(p->data.membersince,date);
 
    set_date(day1,month1,year1);
    gotoxy(20,pos+=2);
    printf("Membership duration (in days): ");
    scanf("%d",&p->data.msdays);
    
    skip_days(p->data.msdays);
    day_counter=0;
    
    sprintf(str_day,"%d",day); //to convert int to string
    sprintf(str_month,"%d",month); 
    sprintf(str_year,"%d",year); 
    strcpy(end_date,"");
    strcat(end_date,str_day);
    strcat(end_date," - ");
    strcat(end_date,str_month);
    strcat(end_date," - ");
    strcat(end_date,str_year);
    strcpy(p->data.end_date,end_date);
    gotoxy(20,pos+=2);
    
    printf("Height(in m): ");
    scanf("%f",&p->data.height);
    gotoxy(20,pos+=2);

    printf("Weight(in kgs): ");
    scanf("%f",&p->data.weight);
    gotoxy(20,pos+=2);

    printf("Workout Type: ");
    scanf("%d",&p->data.workout_type);
    gotoxy(20,pos+=2);

    printf("Diet Type: ");
    scanf("%d",&p->data.diet_type);    
   
    NODE *ptr = head;
   
    if (head == NULL) {head = p;
    p->next=NULL;}
    
    else {
        while (ptr!=NULL && ptr->next!=NULL){
            ptr=ptr->next;

        }
        ptr->next= p;
       
    }
    gotoxy(20,pos+=4);
    printf("MEMBER DATA SUCCESSFULLY ADDED.\n");
    gotoxy(20,pos+=4);
    printf("Do you want to add another member? y/n  :");
    if (getch()=='y') addmember();
    else mainmenu();
    //return;
  
}

int suredelete(int pos){
    gotoxy(20,pos+=2);
    printf("Are you sure you want to delete the data? y/n  :");
    if (getch()=='y') return 1;
    return 0;
}

void removemember() {
    system("cls");
    int pos =3;
    gotoxy(20,pos+=2);
    printf("---------------DELETE MEMBER---------------");
    gotoxy(20,pos+=2);

    printf("Enter Member ID to delete: ");
    scanf("%d",&remove_id);
   
    NODE *ptr = head;
    
    NODE *temp; 
    if ((head!=NULL) && (head->data.member_id==remove_id)){
        if (suredelete(pos)) {
            head=head->next; 
            gotoxy(20,pos+=4);
        printf("Data deleted successfully.");
        }
        gotoxy(20,pos+=4);
        printf("Do you want to delete another member? y/n");
        
        if (getch()=='y') removemember();
        else mainmenu();
     return;
    }
     
     int removed =0;
 
  /*iterating through file data*/
    member a;
    FILE *fp = fopen("gymdata.txt","rb");
    fseek(fp,0,SEEK_SET);
    
    FILE *fpnew=fopen("gymdata2.txt","wb");
    while (fread(&a, sizeof(member),1,fp)){
        if (a.member_id!=remove_id){
            fwrite(&a,sizeof(member),1,fpnew);
        }
        if (a.member_id==remove_id){
            if (suredelete(pos)) { 
                removed = 1;}
            else{
                removed =1;
                fwrite(&a,sizeof(member),1,fpnew);
            }           
            }           
        }
        fclose(fp); fclose(fpnew);
        remove("gymdata.txt"); 
        rename("gymdata2.txt","gymdata.txt");
        //filename="gymdata2.txt";
        if (removed ==1){
            gotoxy(20,pos+=4);
                printf("Do you want to delete another member? y/n");
                
                if (getch()=='y') removemember();
                else mainmenu();
        }

/*******/


    while((ptr != NULL) && (ptr->data.member_id!=remove_id)) {
      
      temp=ptr;
      ptr = ptr->next;
   }

   /*no member found*/
    if ((ptr==NULL) &&  (removed==0))
    {
        gotoxy(20,pos+=2);
    printf("No member ID found.");
    gotoxy(20,pos+=4);
    printf("Do you want to delete another member? y/n  :");
        
        if (getch()=='y') removemember();
        else mainmenu();
    
    }
    /********/

    if (suredelete(pos)) {
        temp->next=ptr->next;
        gotoxy(20,pos+=4);
        printf("Data deleted successfully.");
        }

    gotoxy(20,pos+=4);
    printf("Do you want to delete another member? y/n  :");
    if (getch()=='y') removemember();
    else mainmenu();
    return;
} 

void searchmember(){
    system("cls");
    int printed=0;
    int pos=3;
    gotoxy(20,pos+=2);
    printf("Enter Member ID to search: ");
    gotoxy(20,pos+=1);
    scanf("%d",&remove_id);
    NODE *ptr = head;
    while((ptr != NULL) && (ptr->data.member_id!=remove_id)) {
      ptr = ptr->next;
   }
   /*retrieving data from file*/
    member a;
    FILE *fp = fopen("gymdata.txt","rb");
    while (fread(&a, sizeof(member),1,fp)){
        if (a.member_id==remove_id){
            gotoxy(20,pos+=2);
    printf("Name: %s", a.name);
    gotoxy(20,pos+=2);
    printf("Address: %s", a.address);
    gotoxy(20,pos+=2);
    printf("Contact: %s", a.contact);
    gotoxy(20,pos+=2);
    printf("Date of Birth: %s", a.dob);
    gotoxy(20,pos+=2);
    printf("Member since %s", a.membersince);
    gotoxy(20,pos+=2);
    printf("Membership ends on %s", a.end_date);
    gotoxy(20,pos+=2);
    printf("Height: %.2f m", a.height);
    gotoxy(20,pos+=2);
    printf("Weight: %.2f kgs",a.weight);
    gotoxy(20,pos+=2);
    //printf("Workout type:\n");
 
  
        if (a.workout_type==1){
            printf("---Body building workout---");
            gotoxy(20,pos+=2);
            workout1(pos);
            
            gotoxy(20,pos+=6);
        }
        else {
            printf("---Weight loss workout---");
            gotoxy(20,pos+=2);
            workout2(pos);
            
            gotoxy(20,pos+=5);
        }
        gotoxy(20,pos+=1);
        //printf("Diet plan:\n");
      
        if (a.diet_type==1){
            printf("---Body building diet---");
            gotoxy(20,pos+=2);
            dietplan1(pos);
            
            gotoxy(20,pos+=5);
        }
        else {
            printf("---Weight loss diet---");
            gotoxy(20,pos+=2);
            dietplan2(pos);
            gotoxy(20,pos+=6);
            
        }
        printed =1;
        }
    
    }
    /******/
    if ((ptr==NULL) && (printed==0)){
        gotoxy(20,pos+=2);
        printf("No member ID found.");
        gotoxy(20,pos+=2);
        printf("Do you want to search for another member? y/n");
        if (getch()=='y') removemember();
        else mainmenu();
    return;
    }
    if (printed==0 && ptr!=NULL){
    gotoxy(20,pos+=2);
    printf("Name: %s", ptr->data.name);
    gotoxy(20,pos+=2);
    printf("Address: %s", ptr->data.address);
    gotoxy(20,pos+=2);
    printf("Contact: %s", ptr->data.contact);
    gotoxy(20,pos+=2);
    printf("Date of Birth: %s", ptr->data.dob);
    gotoxy(20,pos+=2);
    printf("Member since %s", ptr->data.membersince);
    gotoxy(20,pos+=2);
    printf("Membership ends on %s", ptr->data.end_date);
    gotoxy(20,pos+=2);
    printf("Height: %.2f m", ptr->data.height);
    gotoxy(20,pos+=2);
    printf("Weight: %.2f kgs", ptr->data.weight);
    gotoxy(20,pos+=2);
    printf("Workout type:\n");
    gotoxy(20,pos+=2);
  
        if (ptr->data.workout_type==1){
            printf("---Body building workout---");
            gotoxy(20,pos+=2);
            workout1(pos);
            
            gotoxy(20,pos+=6);
        }
        else {
            printf("---Weight loss workout---");
            gotoxy(20,pos+=2);
            workout2(pos);
            
            gotoxy(20,pos+=5);
        }
        gotoxy(20,pos+=1);
        printf("Diet plan:\n");
        gotoxy(20,pos+=2);
        if (ptr->data.diet_type==1){
            
            printf("---Body building diet---");
            gotoxy(20,pos+=2);
            dietplan1(pos);
            
            gotoxy(20,pos+=5);
        }
        else {
            printf("---Weight loss diet---");
            gotoxy(20,pos+=2);
            dietplan2(pos);
            gotoxy(20,pos+=6);
            
        }
        }


    fclose(fp);
    gotoxy(20,pos+=4);
    printf("Press ANY KEY to go to main menu");
    if (getch()) mainmenu();
}

void displaylist(){
    system("cls");
    gotoxy(3,6);
    NODE *ptr = head;
   //start from the beginning
   printf("Member_id \t Name \t\t Contact \t Member since \t Membership ends on \t Workout type \t Diet type \n");
   gotoxy(3,7);
   printf("================================================================================================================\n");
   int pos =8;
   member a;
   FILE *fp = fopen("gymdata.txt", "rb");
   while (fread(&a, sizeof(member),1,fp)){
    gotoxy(3,pos+=2);
      printf("%9d \t %-8s \t %-10s \t %-7s \t %-16s \t %1d \t %10d",a.member_id,a.name,a.contact,a.membersince,a.end_date,a.workout_type,a.diet_type);
      printf("\n");
   }
    while(ptr != NULL) {
      gotoxy(3,pos+=2);
      printf("%9d \t %-8s \t %-10s \t %-7s \t %-16s \t %1d \t %10d",ptr->data.member_id,ptr->data.name,ptr->data.contact,ptr->data.membersince,ptr->data.end_date,ptr->data.workout_type,ptr->data.diet_type);
      printf("\n");
      ptr = ptr->next;
   }
   gotoxy(15,pos+=4);
   printf("Press ANY KEY to go to main menu.");
   if (getch()) mainmenu();
	
}

void editmember(){
    system("cls");

    int pos =2;
    gotoxy(20,pos+=2);
    printf("Enter Member ID to edit: ");
    scanf("%d",&remove_id);
    NODE *ptr = head;
    while((ptr != NULL) && (ptr->data.member_id!=remove_id)) {
      ptr = ptr->next;
   }
    if (ptr==NULL){
        gotoxy(20,pos+=2);printf("No member ID found.");
        gotoxy(20,pos+=2);printf("Do you want to search for another member? y/n");
        if (getch()=='y') removemember();
        else mainmenu();
    return;
    }
   
    int c;
    gotoxy(20,pos+=2);
    printf("<1> Contact");gotoxy(20,pos+=2);
    printf("<2> Weight");gotoxy(20,pos+=2);
    printf("<3> Diet type");gotoxy(20,pos+=2);
    printf("What do you want to edit?");
    scanf("%d",&c );

    switch (c){
        case 1:
        gotoxy(20,pos+=2);
            printf("New Contact: ");
            scanf("%s", &ptr->data.contact); break;
        case 2:
        gotoxy(20,pos+=2);
            printf("New Weight: ");
            scanf("%f", &ptr->data.weight); break;
        case 3:
        gotoxy(20,pos+=2);
            printf("New Diet type: ");
            scanf("%f", &ptr->data.diet_type); break;
        default:
        gotoxy(20,pos+=4);
            printf("\aINVALID ENTRY!!! Please re-entered correct option");
            if(getch())
            editmember();
    }
    gotoxy(20,pos+=4);

    printf("Press ANY KEY to go to main menu");
    if (getch()) mainmenu();
}

int mainmenu(){
    system("cls");
    int i,pos; float bmi,h,w;
    gotoxy(20,3);
    printf(" \t\tMAIN MENU \n ");
    printf("\t\t------------------------------------------\n");
    gotoxy(20,5);
    printf("<1> Add Members");
    gotoxy(20,7);
    printf("<2> Remove Members");
    gotoxy(20,9);
    printf("<3> Search Members");
    gotoxy(20,11);
    printf("<4> View Member's list");
    gotoxy(20,13);
    printf("<5> Edit Members Record");
    gotoxy(20,15);
    printf("<6> BMI Calculator");
    gotoxy(20,17);
    printf("<7> Close Application");
    
    //t();
    gotoxy(20,20);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        addmember();
        break;

        case '2':
        removemember();
        break;

        case '3':
        searchmember();
        break;

        case '4':
        displaylist();
        break;

        case '5':
        editmember();
        break;
   
        case '6':
        system("cls");
        pos = 1;
        gotoxy(23,pos+=2);
        printf("---------------BMI CALCULATOR---------------");
        gotoxy(23,pos+=2);
        printf("Enter weight(in kgs): ");
        scanf("%f",&w);
        gotoxy(23,pos+=2);
        printf("Enter height(in m): ");
        scanf("%f",&h);
        bmi=bmicalc(w,h);
        gotoxy(23,pos+=2);
        printf("Body Mass Index: %f ",bmi);
        gotoxy(23,pos+=2);
        if (bmi<18.5) printf("Underweight. ");
        else if (18.5<=bmi && bmi<24.9) printf("Healthy weight.");
        else if (25<=bmi && bmi<29.9) printf("Overweight. ");
        else printf("Obese");
        gotoxy(23,pos+=5);
        printf("Press ANY KEY to go back to main menu.");
        if (getch()) mainmenu();
        break;

        case '7':
        {

        FILE *gymfp=fopen("gymdata.txt","ab+");
        system("cls");
        NODE *ptr=head;
        fseek(gymfp, 0,SEEK_END);
         while(ptr != NULL) {
           fwrite(&ptr->data,sizeof(member),1,gymfp);
            ptr = ptr->next;
        }
        gotoxy(23,3);
        printf("\t---Gym Management System---");
        gotoxy(16,5);
        printf("\t---Project by Tejasree M S---");
        gotoxy(15,11);
        printf("\t\tApplication closing...");
        gotoxy(16,20);
        exit(0);
        }

        default:
        {
        gotoxy(20,25);
        printf("\aINVALID ENTRY!!! Please re-entered correct option");
        if(getch())
        mainmenu();

        }

    }
    
}

int main(){

    mainmenu();
    return 0;

}

