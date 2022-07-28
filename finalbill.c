#include <stdio.h>
#include <time.h>
#include <string.h>
void main()
{
    int i;
    char name[100];
    int count = 0, grandtotal;
    float gst = 0.00, sum = 0.00;
    char menu[][1000] = {"RICE        ", "DAL TADKA   ", "PALAK PANEER", "MIX-VEG     ", "MATAR PANEER", "ROTI        "};
    int price[] = {200, 200, 400, 350, 400, 30};
    size_t size = sizeof(menu) / sizeof(menu[0]);
    int total[100], qty[100][200], items[11][200];
    int len = 0, flag = 0, m = 0, flag2 = 0,itemtemp;
    // int digits_only( itemtemp);

    printf("\n============================================================\n");
    printf("\n================== Welcome to Taj Skyline ==================\n");
    printf("\n\t\t    Sindhu Bhavan Marg,\n");
    printf("\t\t    PRL Colony, Thaltej,\n");
    printf("\t\t    Ahmedabad, Gujarat 380058\n");
    printf("\t\t    Phone: 079-4040-0000\n");
    time_t t = time(NULL);
    printf("\n----------------------------------- %s\n\n", ctime(&t));

    printf("-----------------------------------------------------------\n");
    printf("Sr.    |    \tMenu Items\t  \t |\tPrice     |\n");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < size; i++)
    {
        printf(" %d.    |\t %s\t \t | \t %d  \n", i + 1, menu[i], price[i]);
    }
previous:
    printf("\n\nEnter name of the customer : ");
    scanf("%s", &name);
    len = strlen(name);
    // name[i] != '\0'
    for (i = 0; i < len; i++)
    {
        if (name[i] == '0' || name[i] == '1' || name[i] == '2' || name[i] == '3' || name[i] == '4' || name[i] == '5' || name[i] == '6' || name[i] == '7' || name[i] == '8' || name[i] == '9')
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
    printf("\nEnter Item no. %d = ", count + 1);
    scanf("%d", &itemtemp);

    if ((itemtemp <= size)&&(itemtemp>=1))
    {
        items[0][200] = itemtemp;
        count++;
    }
    else
    {

        printf("\nEntered item does not exist , Please try again\n");
        goto next;
    }
    printf("\nSelected : %s", menu[items[0][200] - 1]);
    printf("\nQuantity : ");
    scanf("%d", &qty[0][200]);
    total[0] = qty[0][200] * price[items[0][200] - 1];
    printf("Total\t : %d*%d = %d", qty[0][200], price[items[0][200] - 1], total[0]);
    printf("\n\n--------------------------------------------------------------\n");
    printf("\n");
    int n = askitem();
    switch (n)
    {
    case 1:
        for (i = 1; i <= size; i++)
        {
            next2:
            printf("\n--------------------------------------------------------------\n");
            printf("\nEnter Item no. %d = ", count + 1);
            scanf("%d", &itemtemp);
            if ((itemtemp <= size)&&(itemtemp>=1))
            {
                // scanf("%d", &items[0][200]);
                items[i][200] = itemtemp;
                // itemtemp = 0;
                count++;
            }
            else
            {

                printf("\nEntered item does not exist , Please try again\n");
                // itemtemp = 0;
                goto next2;
            }
            // scanf("%d", &items[i][200]);
            // count++;
            int itemcount = items[i][200];
            printf("\nSelected : %s", menu[itemcount - 1]);
            printf("\nQuantity : ");
            scanf("%d", &qty[i][200]);
            int qtycount = qty[i][200];
            total[i] = qty[i][200] * price[itemcount - 1];
            printf("Total\t : %d*%d = %d", qty[i][200], price[itemcount - 1], total[i]);
            printf("\n\n--------------------------------------------------------------");
            printf("\n");

            int n = askitem();
            if (n == 0)
            {
                goto end;
            }
        }
        break;
    case 0:
        goto end;

    default:
        break;
    }
end:

    printf("\n\n===============================================================\n");
    printf("====================== PRINTING THE BILL ======================\n");
    printf("\n\t\t         Taj Skyline\n");
    printf("\n\t\t     Sindhu Bhavan Marg,\n");
    printf("\t\t     PRL Colony, Thaltej,\n");
    printf("\t\t     Ahmedabad, Gujarat 380058\n");
    printf("\t\t     Phone: 079-4040-0000\n");
    printf("--------------------------------------------------------------\n");
    printf("NAME OF THE CUSTOMER : %s\n", name);
    // printf("%d",sizeof(items)/sizeof(items[0]));
    printf("--------------------------------------------------------------");
    printf("\nSr.   |   Menu Items       |   Qty   |   Price   |   Total   |\n");
    printf("--------------------------------------------------------------");

    for (i = 0; i < count; i++)
    {
        int itemcount = items[i][200];
        printf("\n%d     |    %s    |    %d    |    %d    |    %d    |\n", i + 1, menu[items[i][200] - 1], qty[i][200], price[itemcount - 1], qty[i][200] * price[itemcount - 1]);
    }
    printf("--------------------------------------------------------------");
    // sum =0;
    for (i = 0; i < count; i++)
    {
        int itemcount = items[i][200];
        sum += (qty[i][200] * price[items[i][200] - 1]);
    }
    // printf("%f\n",sum);

    gst = sum * 0.18;

    // printf("%f\n",gst);
    printf("\n Total (Excl. GST)\t\t\t\t   :");
    printf(" %.2f ", sum);
    printf("\n CGST @9%% \t\t\t\t\t   :");
    printf(" %.2f ", gst / 2);
    printf("\n SGST @9%% \t\t\t\t\t   :");
    printf(" %.2f ", gst / 2);
    printf("\n Grand Total (Incl. of 18%% GST)\t\t\t   :");
    printf(" %.2f ", sum + gst);
    printf("\n--------------------------------------------------------------\n");
    printf("\tNote : Prices are inclusive of all Govt. taxes \n");
    printf("\t\t  Thanks for visiting\n");
    printf("--------------------------------------------------------------\n");
}

int askitem()
{
    int n;
    next3:
    printf("\nPress  1 for adding another item\nPress 0 for generating bill\n ");
    printf("\nEnter Your Choice = ");
    scanf("%d", &n);

    if(n==0||n==1)
    {
        goto next4;
    }

    else{
        goto next3;
    }
    next4:
    return n;
}
