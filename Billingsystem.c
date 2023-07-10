#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure
struct items
{
    char name[50];
    float price;
    int quantity;
};

struct info
{
    char customer[50];
    char date[50];
    int noofitems;
    struct items itm[50];
};
void billheader(char name[50] , char date [30]);
void billbody(char item[50] , int quantity , float price );
void billfooter(float total);

//main function
int main()
{
    int num, n, j;
    struct info i;
    struct info bill;
    char savebill = 'y';
    char cname[50];
    FILE *fp ;
    int invoice = 0;
    float total;
    char conti;
    char nam[50];
    printf("Enter the name of your store: ");
    scanf("%s", nam);   

    cont:
    printf("\t\t=====%s=====\n", nam);
    printf("\t\tWhat would you like to do?\n\n");
    printf("\t1. Generate Invoice\n");
    printf("\t2. Show all Invoice\n");
    printf("\t3. Search Invoice\n");
    printf("\t4. Exit\n");
    printf("\tEnter the number of operation you want to carry: ");
    scanf("%d", &num);
    getchar();

    switch (num)
    {
    case 1:
    system("cls");
        printf("\tEnter the name of customer: ");
        fgets(i.customer, 50, stdin);
        i.customer[strlen(i.customer) - 1] = '\0';
        strcpy(i.date, __DATE__);
        printf("\tEnter the number of items: ");
        scanf("%d", &n);
        getchar();
        i.noofitems = n;


        for (j = 0; j < n; j++)
        {
            printf("\n\n");
            printf("\tEnter the name of item %d: ", j+1);
            fgets(i.itm[j].name, 50, stdin);
            i.itm[j].name[strlen(i.itm[j].name) - 1] = '\0';
            printf("\tEnter the quantity of item %d: ", j+1);
            scanf("%d", &i.itm[j].quantity);
            printf("\tEnter the price of item %d: ", j+1);
            scanf("%f", &i.itm[j].price);
            getchar();
            total = total + i.itm[j].quantity * i.itm[j].price;

        }
            billheader(i.customer , i.date);
    for ( j = 0; j < i.noofitems ; j++)
    {
        billbody(i.itm[j].name , i.itm[j].quantity , i.itm[j].price);
    }
    billfooter(total);
    printf("Do you want to save the bill(y/n)?\t");
    scanf("%c", &savebill);

    if (savebill == 'y')
    {
        fp = fopen("RestraurantBill.txt" , "ab");
        fwrite(&i , sizeof(struct info) , 1 , fp);
        if (fwrite != 0)
        {
            printf("Successfully saved");
        }
        else
        printf("Some problem occured");
        fclose(fp);
        }
        break;
         case 2:
    system("cls");
        fp = fopen("RestraurantBill.txt", "rb");
        
        printf("\n*****Your All Invoices*****\n");
        while (fread(&bill, sizeof(struct info), 1, fp))
        {
            
        float tot = 0;
            billheader(bill.customer, bill.date);
            for (int j = 0; j < bill.noofitems; j++)
            {
                billbody(bill.itm[j].name, bill.itm[j].quantity, bill.itm[j].price);
                tot += bill.itm[j].quantity * bill.itm[j].price;
            }
            billfooter(tot);
        }
        fclose(fp);
        break;
    case 3:
    system("cls");
    printf("Enter the name of the customer: ");
    fgets(cname, 50, stdin);
    cname[strcspn(cname, "\n")] = '\0';

    fp = fopen("RestraurantBill.txt", "rb");
    printf("\n*****Your All Invoices*****\n");
    
    while (fread(&bill, sizeof(struct info), 1, fp))
    {
        float tot = 0;
        if (!strcmp(bill.customer, cname))
        {
            printf("Bill of %s\n", cname);
            billheader(bill.customer, bill.date);
            
            for (int j = 0; j < bill.noofitems; j++)
            {
                billbody(bill.itm[j].name, bill.itm[j].quantity, bill.itm[j].price);
                tot += bill.itm[j].quantity * bill.itm[j].price;
            }
            
            billfooter(tot);
            invoice = 1;
        }
    }
    
    if (!invoice)
        printf("No invoice found\n");
    
    fclose(fp);
    break;

    case 4:
    system("cls");
    printf("Thank you for using our service\n");
    break;
    }
   printf("Do you want to continue (y/n)? ");
scanf(" %c", &conti);  // Add a space before %c to skip any leading whitespace

if (conti == 'y' || conti == 'Y') {
    goto cont;
} else 
 printf("Thank you for using our service\n");

    return 0;
}

void billheader(char name[30], char date[30])
{
    printf("\n\n");
    printf("\t\t  ABC RESTRO");
    printf("\n-----------------------------------");
    printf("\n Date: %s" , date);
    printf("\n Invoice to: %s", name);
    printf("\n\n\n");
    printf("------------------------------------------------\n");
    printf("Items\t\t");
    printf("Quantity\t\t");
    printf("price\t\t");
    printf("\n-------------------------------------------------");
    printf("\n\n");


}

void billbody(char items[50] , int quantity , float price)
{
    
    printf("%s\t\t\t", items);
    printf("%d\t\t", quantity);
    printf("%f\t" , price * quantity);
    printf("\n\n");
}

void billfooter(float total ){
    printf("\n");
    float dis = 0.1 * total;
    float ntotal = total - dis;
    float cgst = ntotal * 0.09;
    float sgst = ntotal * 0.09;
    float grandTotal = ntotal + 2 * cgst;
    printf("--------------------------------------------\n");
    printf("Sub total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f","%", dis);
    printf("\n-------------------------------------------\n");
    printf("Net Total\t\t\t%.2f", ntotal);
    printf("\nCGST @9%s\t\t\t%.2f" , "%" , cgst);
    printf("\nSGST @9%s\t\t\t%.2f" , "%" , sgst);
    printf("\n----------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n----------------------------------------\n");

}