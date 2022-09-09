#include <stdio.h>
#include <time.h>
#include <string.h>
void main()
{
    int i,count = 0, grandtotal,len = 0, flag = 0, m = 0, flag2 = 0; //integer variables 
    int total[100], qty[100][200], items[11][200],price[] = {200, 200, 400, 350, 400, 30};//integer arrays
    float itemtemp,gst = 0.00, sum = 0.00;//float variables
    char name[30],menu[][1000] = {"RICE        ", "DAL TADKA   ", "PALAK PANEER", "MIX-VEG     ", "MATAR PANEER", "ROTI        "};//character array
    size_t size = sizeof(menu) / sizeof(menu[0]);//for size of menu
    time_t t = time(NULL);//for date and time
    float qtycount;
    //welcome screen with menu items//
    printf("\n============================================================\n");
    printf("\n================== Welcome to Taj Skyline ==================\n");
    printf("\n\t\t    Sindhu Bhavan Marg,\n");
    printf("\t\t    PRL Colony, Thaltej,\n");
    printf("\t\t    Ahmedabad, Gujarat 380058\n");
    printf("\t\t    Phone: 079-4040-0000\n");
    printf("\n----------------------------------- %s\n\n", ctime(&t));
    printf("-----------------------------------------------------------\n");
    printf("Sr.    |    \tMenu Items\t  \t |\tPrice     |\n");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < size; i++)//printing menu items
    {
        printf(" %d.    |\t %s\t \t | \t %d  \n", i + 1, menu[i], price[i]);
    }
previous: //start of the bill generation
    printf("\n\nEnter name of the customer : ");
    gets(name);
    len = strlen(name);
    // name[i] != '\0'
    for (i = 0; i < len; i++)//to prevent user from entering numbers in name field
    {
        if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4' || name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9' || name[i] == '@' || name[i] == '~' || name[i] == '!' || name[i] == '#' || name[i] == '$' || name[i] == '%' || name[i] == '^' || name[i] == '&' || name[i] == '*' || name[i] == '(' || name[i] == ')' || name[i] == '_' || name[i] == '-'  || name[i] == '=' || name[i] == '+')
        {
            flag = flag + 1;
        }
    }
    if (flag == 0)
    {
        goto next;
    }
    else
    {
        printf("\nPLEASE ENTER A VALID NAME\n");
        flag = 0;
        goto previous;
    }

next:
    printf("\n--------------------------------------------------------------\n");
    printf("\nEnter Item no. %d = ", count + 1); //to take the input for menu items
    scanf("%f", &itemtemp);

        // int convitemtemp = itemtemp;

        if ((itemtemp <= size)&&(itemtemp>=1)) //to  prevent user from entering out of the menu items
        {

           items[0][200] = itemtemp;
           count++;
        }
        else
        {
            printf("\nEntered item does not exist , Please try again\n");
            goto next;
        }
    printf("\nSelected : %s", menu[items[0][200] - 1]);//to show what user have selected 
    printf("\nQuantity : "); //getting the quantity
    scanf("%f", &qtycount);
    qty[0][200] = qtycount;
    total[0] = qty[0][200] * price[items[0][200] - 1];
    printf("Total\t : %d*%d = %d", qty[0][200], price[items[0][200] - 1], total[0]);//showing the temporary subtotal and overview of previous selection
    printf("\n\n--------------------------------------------------------------\n");
    printf("\n");
    int n = askitem(); //function to ask user to add more item or generating bill
    switch (n)//switch case for selection of adding more item or generate bill
    {
    case 1://to add item
        for (i = 1; i <= size; i++)
        {
            next2:
            printf("\n--------------------------------------------------------------\n");
            printf("\nEnter Item no. %d = ", count + 1);
            scanf("%f", &itemtemp);
            if ((itemtemp <= size)&&(itemtemp>=1))//again to prevent user from entering out of menu items
            {
                items[i][200] = itemtemp;
                count++;
            }
            else
            {

                printf("\nEntered item does not exist , Please try again\n");
                goto next2;
            }
            int itemcount = items[i][200];
            printf("\nSelected : %s", menu[itemcount - 1]);
            printf("\nQuantity : ");
            scanf("%f", &qtycount);
            qty[i][200] = qtycount;
            total[i] = qty[i][200] * price[itemcount - 1];
            printf("Total\t : %d*%d = %d", qty[i][200], price[itemcount - 1], total[i]);
            printf("\n\n--------------------------------------------------------------");
            printf("\n");

            int n = askitem();//to ask user for adding one more item or generate bill
            if (n == 0)//case 0 is for fgeneration of bill
            {
                goto end;//to jump to the start of bill genertionn
            }
        }
        break;
    case 0://for genneration of bill
        goto end;

    default:
        break;
    }
end:
//start  of printing the bill
    printf("\n\nGenerating the bill............................................\n\n");
    printf("\n\n===============================================================\n");
    printf("========================= BILL TO PAY =========================\n");
    printf("\n\t\t         Taj Skyline\n");
    printf("\n\t\t     Sindhu Bhavan Marg,\n");
    printf("\t\t     PRL Colony, Thaltej,\n");
    printf("\t\t     Ahmedabad, Gujarat 380058\n");
    printf("\t\t     Phone: 079-4040-0000\n");
    printf("--------------------------------------------------------------\n");
    printf("\n------------------------------------- %s\n", ctime(&t));//for time
    printf("NAME OF THE CUSTOMER : %s\n", name);//for name
    printf("--------------------------------------------------------------");
    printf("\nSr.   |   Menu Items       |   Qty   |   Price   |   Total   |\n");
    printf("--------------------------------------------------------------");
    // system("pause");l

    for (i = 0; i < count; i++)//to print  menu ,qty,price,total
    {
        int itemcount = items[i][200];
        printf("\n%d     |    %s    |    %d    |    %d    |    %d    |\n", i + 1, menu[items[i][200] - 1], qty[i][200], price[itemcount - 1], qty[i][200] * price[itemcount - 1]);
    }
    printf("--------------------------------------------------------------");
    for (i = 0; i < count; i++)//for the sum of all total(grand-total) of seperate  item
    {
        int itemcount = items[i][200];
        sum += (qty[i][200] * price[items[i][200] - 1]);
    }

    gst = sum * 0.18;
    printf("\n Total (Excl. GST)\t\t\t\t   :");
    printf(" %.2f ", sum);
    printf("\n CGST @9%% \t\t\t\t\t   :");
    printf(" %.2f ", gst / 2);
    printf("\n SGST @9%% \t\t\t\t\t   :");
    printf(" %.2f ", gst / 2);
    printf("\n--------------------------------------------------------------");
    printf("\n Grand Total (Incl. of 18%% GST)\t\t\t   :");
    printf(" %.2f ", sum + gst);
    printf("\n--------------------------------------------------------------\n");
    printf("\tNote : Prices are inclusive of all Govt. taxes \n");
    printf("\t\t  Thanks for visiting\n");
    printf("--------------------------------------------------------------\n");
    // system("pause");
    
}

int askitem()//function to ask user for adding one more item or generation of bill
{
    float n;
    next3:
    printf("\nPress  1 for adding another item\nPress 0 for generating bill\n ");
    printf("\nEnter Your Choice = ");
    scanf("%f", &n);

    if(n==0||n==1)
    {
        goto next4;
    }

    else{
        goto next3;
    }
    next4:
    return n;
    // system("pause");
}
