#include<stdio.h>
#include<conio.h>

void record();
void display();
void cost();
void price();
void quantity();
void avgcost();
void avgprice();
int ch;
int no;
int no2;
int i;
int c;
int quant = 0;


struct inventory{

char name[20];
int id;
int cost;
int quantity;
int price;
}t1;


int main()
{


    do
    {
        printf("\n\tWELCOME TO RAIHAN INVENTORY SYSTEM\n");
        printf("\n");
        printf("Press 1: ADD RECORD\n");
        printf("Press 2: DISPLAY RECORD\n");
        printf("press 3: TOTAL COST\n");
        printf("Press 4: TOTAL PRICE\n");
        printf("Press 5: TOTAL QUANTITY\n");
        printf("Press 6: AVERAGE PRICE\n");
        printf("Press 7: AVERAGE COST\n");
        printf("\n");
        printf("Enter your Choice\n");
        scanf("%d", &ch);
        switch (ch)

        {
            case 1: record();
            break;

            case 2: display();
            break;

            case 3: cost();
            break;

            case 4: price();
            break;

            case 5: quantity();
            break;

            case 6: avgprice();
            break;

            case 7: avgcost();
            break;

            case 8:
            break;

            default: printf("\n INVALID CHOICE\n");
            break;
        }

    }while (ch != 8);


   return(0);

}

void record()
{

    printf("HOW MANY RECORDS DO YOU WANT TO STORE\n");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("nabeel.txt", "w");
    for (i=0; i<no; i++)
    {
       printf("Enter The Product Name\n");
       scanf("%s", t1.name);

       printf("Enter the product id: ");
       scanf("%d",&t1.id);

       printf("Enter the Product Cost\n");
       scanf("%d", &t1.cost);

       printf("Enter the Product Quanitity\n");
       scanf("%d", &t1.quantity);

       printf("Enter the Product Price\n");
       scanf("%d", &t1.price);

       fprintf(fp, "PRODUCT NAME     :    %s\n", t1.name);
       fprintf(fp, "PRODUCT ID       :    %d\n", t1.id);
       fprintf(fp, "PRODUCT COST     :    %d\n", t1.cost);
       fprintf(fp, "PRODUCT QUANTITY :    %d\n", t1.quantity);
       fprintf(fp, "PRODUCT PRICE    :    %d\n\n", t1.price);
    }

       fclose(fp);


}
void display()
{

    FILE *fp;
    fp = fopen("nabeel.txt", "r");
    while ((c=getc(fp)) != EOF)
    {
       printf("%c", c);
    }
     fclose(fp);
     getch();


}
void cost()
{
    int totalcost = 0;
    FILE *fp;
    fp = fopen("nabeel.txt", "r");
    printf("HOW MANY RECORDS\n");
    scanf("%d", &no);
    for (i=0; i<no; i++)
    {
       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1.name);
       fscanf(fp, "PRODUCT ID       :    %d\n", &t1.id);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1.cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1.quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1.price);
       totalcost = totalcost + t1.cost;
    }
    printf("\n\ntotal cost is :  %d", totalcost);
    fclose(fp);
    getch();

}
void price()
{
    int total = 0;
    printf("HOW MANY RECORDS :  ");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("nabeel.txt", "r");
     for (i=0; i<no; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1.name);
       fscanf(fp, "PRODUCT ID       :    %d\n", &t1.id);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1.cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1.quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1.price);
       total = total + t1.price;

    }
    printf("The Total Price is %d\n", total);
    fclose(fp);
    getch();


}
void quantity()
{
    printf("HOW MANY RECORDS\n");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("nabeel.txt", "r");
     for (i=0; i<no; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n",  &t1.name);
       fscanf(fp, "PRODUCT ID       :    %d\n", &t1.id);
       fscanf(fp, "PRODUCT COST     :    %d\n",  &t1.cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n",  &t1.quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1.price);
       quant = quant + t1.quantity;

    }
    printf("The Total quantity is %d\n", quant);
    fclose(fp);
    getch();


}



void avgprice()
{
    int avg;
    int t = 0;
    printf("HOW MANY RECORDS :  ");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("nabeel.txt", "r");
    for (i=0; i<no; i++)
        {
       fscanf(fp, "PRODUCT NAME     :    %s\n",  &t1.name);
       fscanf(fp, "PRODUCT ID       :    %d\n", &t1.id);
       fscanf(fp, "PRODUCT COST     :    %d\n",  &t1.cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n",  &t1.quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1.price);
       t = t + t1.price;

    }
    avg =t/no;
    printf("The Average Price is %d", avg);
    fclose(fp);
    getch();

}
void avgcost()
{
    int costavg = 0;
    int costtotal = 0;
    FILE *fp;
    fp = fopen("nabeel.txt", "r");
    printf("HOW MANY RECORDS YOU WANT TO SEARCH\n");
    scanf("%d", &no);
    for (i=0; i<no; i++)
    {
       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1.name);
       fscanf(fp, "PRODUCT ID       :    %d\n", &t1.id);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1.cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1.quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1.price);
       costtotal = costtotal + t1.cost;
    }
    costavg =costtotal/no;
    printf("\n\n THE AVERAGE COST IS   :%d", costavg);
    fclose(fp);
    getch();

}
