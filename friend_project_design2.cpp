#include<iostream>
using namespace std;
class product
{	
	public:
		string product_name;
		int qty;
		float price, total=0;
		friend class customer;
		void get_product_info()
		{
				cout<<"\t\tENTER THE NAME OF PRODUCT :: ";
				cin>>product_name;
				cout<<"\n\t\tENTER THE PRICE OF PRODUCT :: ";
				cin>>price;
				cout<<"\n\t\tENTER THE QUANTITY OF PRODUCT :: ";
				cin>>qty;
				total=price*qty;
					
		}
		static void display_product_header()
		{
			cout<<"\t _______________________________________________________________________________________________________"<<endl;
 			cout<<"\t|\tSERIAL NUMBER\t|\t"<<"PRODUCT NAME\t|\t"<<"PRICE\t|\t"<<"QUANTITY\t|\t"<<"TOTAL\t|"<<endl;
			cout<<"\t|-----------------------|-----------------------|---------------|-----------------------|---------------|"<<endl;
		}
		static void display_product_bottom()
		{
			cout<<"\t|_______________________|_______________________|_______________|_______________________|_______________|"<<endl;	
		}		
};
class customer
{
	public:
		product p[100];
		string name;
		static int billno;
		float final_amt;
		int no_of_products;
		friend class product;
		int billnum;
		void get_customer_info()
		{
			billno++;
			cout<<"\n\t\t\t\t****************** BILL NUMBER :: "<<billno<<" ******************"<<endl;
			billnum=billno;
			
			cout<<"\n\tENTER NAME OF CUSTOMER :: ";
			cin>>name;
			cout<<"\n\tENTER THE NUMBER OF PRODUCTS :: ";
			cin>>no_of_products;
			for(int i=1;i<=no_of_products;i++)
			{
				cout<<"\n\t\t\t********PRODUCT NUMBER :: "<<i<<"********\n"<<endl;
				p[i].get_product_info();
				final_amt=final_amt+p[i].total;	
			}
			cout<<"\n\t\t\t\t\tTHE TOTAL AMOUNT IS :: "<<final_amt<<endl;
		}
		void display_by_bill(int bill)
		{
			cout<<"\n\t\tCUSTOMER NAME :: "<<name<<"\n"<<endl;
			product::display_product_header();
			for(int i=1;i<=no_of_products;i++)
			{
				cout<<"\t|\t\t"<<i<<"\t|\t"<<p[i].product_name<<"\t\t|\t"<<p[i].price<<"\t|\t"<<p[i].qty<<"\t\t|\t"<<p[i].total<<"\t|"<<endl;
			}
			product::display_product_bottom();
			cout<<"\n\t\tTHE TOTAL AMOUNT IS :: "<<final_amt<<"\n\n"<<endl;
			
		}		
};
	
int customer::billno=0;

int main()
{
	int choice, count;
	customer c[100];
	int i=1; 
	cout<<"                                    _______________________________________________________________________"<<endl;
	cout<<"                                   |                 _     _  _  _ _ _      __        _                    |\n";
	cout<<"                                   |  *             |_ |_|| ||_||_| |  |\\ || _   |\\/||_|| |             *  |\n";
	cout<<"                                   |  *              _|| ||_||  |  _|_ | \\||_|   |  || ||_|_            *  |\n";
	cout<<"                                   |_______________________________________________________________________|\n";
	do
	{
		cout<<"\n\t1. NEW PURCHASE\n\t2. DISPLAY BILL BY BILL NUMBER\n\t3. DISPLAY ALL BILLS\n\t4. DISPLAY TODAYS COLLECTION\n\t5. EXIT"<<endl;
		cout<<"\n\t   ENTER YOUR CHOICE :: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					c[i].get_customer_info();
					i++;
					break;
				}
			case 2:
				{
					int bill;
					cout<<"\n\t\tENTER THE BILL NUMBER :: ";
					cin>>bill;
					if(bill<=customer::billno && bill>0)
					{
						for(int i=1;i<=customer::billno;i++)
						{
							if(bill==c[i].billnum)
							{
								cout<<"________________________________________________________________________________________________________________________________________________________________"<<endl;
								c[i].display_by_bill(bill);
								cout<<"________________________________________________________________________________________________________________________________________________________________"<<endl;
							}
						}
					}
					else
					{
						cout<<"\n\t\t\t\t!!!BILL NOT FOUND!!!"<<endl;
						cout<<"\n\t\t\tCHECK YOUR BILL NUMBER AGAIN !!!"<<endl;
					}
					break;
				}
			case 3:                             
				{
					for(int i=1;i<=customer::billno;i++)
					{
						cout<<"________________________________________________________________________________________________________________________________________________________________"<<endl;
						cout<<"\n\t\tBILL NUMBER ::"<<i<<endl;
						c[i].display_by_bill(i);
						cout<<"________________________________________________________________________________________________________________________________________________________________"<<endl;	
					}
					break;
				}		
			case 4:
				{       
					float collection_today=0;   
					for(int i=1;i<=customer::billno;i++)
					{
						collection_today=collection_today+c[i].final_amt;
					}
					cout<<"\n\n\t\t\tTODAYS COLLECTION IS :: "<<collection_today<<endl;
					break;    	
				}
			case 5:
				{
					break;	
				}	
			default:
				{
					cout<<"\t\tINVALID CHOICE";
				}	
		}
	}
	while(choice!=5);
	return 0;		
}