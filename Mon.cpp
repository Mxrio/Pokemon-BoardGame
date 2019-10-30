#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

 
//This is the creation of the pokemon
class Mon
{
private:
	string name;
	int Hp;
	int attack1Pow;
	string attack1Name;
	int attack2Pow;
	string attack2Name;

public:
	//We can get and set the values for the creation of new pokemon here
	string GetName()
		{
			return name;
		}
 
	void  SetName(string name)
		{
			this->name=name;
		}
	int GetHP()
		{
			return Hp;
		}
	void SetHp(int Hp)
		{
			this->Hp=Hp;
		}
	int GetAttack1Pow()
		{
			return attack1Pow;
		}
	string GetAttack1Name()
		{
			return attack1Name;
		}
	void SetAttack1Pow(int attack1Pow)
		{
			this->attack1Pow=attack1Pow;
		}
	void SetAttack1Name(string attack1Name)
		{
			this->attack1Name=attack1Name;
		}
	int GetAttack2Pow()
		{
			return attack2Pow;
		}
		
	string GetAttack2Name()
		{
			return attack2Name;
		}
	void SetAttack2Pow(int attack2Pow)
		{
			this->attack2Pow=attack2Pow;
		}
	void SetAttack2Name(string attack2Name)
		{
			this->attack2Name=attack2Name;
		}
};

//I define an array of Mons and store their values	
 Mon poke[2];
	
	

//This is the player class
class Player
{
private:
	int gender;
	string name;
	vector <Mon> CatchedMon;
	int money= 500;

public:
	//here we simply set the values for each value for the player
	void GetName()
	{
		cout <<name;
	}
	
	void SetName( string name)
	{
		 this->name=name;
	}
	
	void SetGender()
	{
		cin>> gender;
		cout<<endl;
	}

	int GetGender()
	{
		return gender;
	}

	int GetMoney()
	{
		return money;
	}
	
	void SetMoney(int money)
	{
		this->money=money;
	}

	void AddCatched(Mon New)
	{
		CatchedMon.push_back(New);
	}

	void ViewCatchedMon()
	{

		if(CatchedMon.size()==0)
		{
			cout<<"You don't have any Pokiman catched! Go out and catch some!"<<endl;
		}
	
		cout<<"The Mon that you have catched are "<<endl;
			for(int i=0; i<CatchedMon.size(); i++)
			{
				cout<<CatchedMon[i].GetName() <<endl;
			}		
	}

	Mon MonSelect()
	{
		int opt;
		
		if(CatchedMon.size()==0)
		{
			cout<<"You don't have any Pokiman catched! Go out and catch some!"<<endl;
		
		}

		else
		{
			cout<<"Which Pokiman do you want to select?"<<endl;
				for(int i=0; i<CatchedMon.size(); i++)
				{
					int MonNum=1;
					cout<<"for " << CatchedMon[i].GetName()<<"Press "<< MonNum<<endl;
					cout<<CatchedMon[i].GetName()<<" has "<<CatchedMon[i].GetHP()<<"HP"<<endl;
					cout<<endl;
					MonNum++;
				}
				cin>>opt;		
				
				if(opt==1)
				{
					return CatchedMon[0];
				}
			
				if(opt==2)
				{
					return CatchedMon[1];
				}
		
				if(opt==3)
				{
					return CatchedMon[2];
				}

				if(opt==4)
				{
					return CatchedMon[3];
				}
		}
	}

	int NoOneLeft()
	{
		if((CatchedMon[0].GetHP()+CatchedMon[1].GetHP()+CatchedMon[2].GetHP()+CatchedMon[3].GetHP())<=0)
		{
			return 0;
		}		
	}
};

	Player player1;


class Bag
{
private:
	int itm[2];
	
public:	
	void AddItm(int itmIndx,int itmAmmount )
	{
			itm[itmIndx]= itm[itmIndx]+itmAmmount; 
	}

	void InsideBag()
	{	
		bool isRunning;
		int opt;

		cout<<"You have"<< endl<<itm[0]<< " Pokibals"<<endl<< itm[1]<<" Potions"<<endl<< itm[2]<< " HyperPotions"<<endl;
		cout<<" Select the item you want to use."<<endl;
		cout<<"1 for Pokibal"<<endl;
		cout<<"2 for Potion"<<endl;
		cout<<"3 for HyperPotions"<<endl;
		cin>>opt;
		cout<<endl;
			/*			
			if(opt== 1)
			{
				
			}
			*/	
	}		
};

	Bag bag;

class Item
{
private:
	string name;
	int price;
	
public:
	void SetPrice(int price)
	{
		this->price=price;
	}
	
	int GetPrice()
	{
		return price;
	}
	
	void SetName(string name)
	{
		this->name=name;
	}
	
	string GetName()
	{
		return name;
	}
	
};
//This is the shop function, we are going to call this function will only be able to be called in the overwolrd funcion
void Shop(int money)
{
	

	int opt=0;
	int YorN;
	int itmAmount;
	Item item[5];  
	
	item[0].SetName("Pokeball");
	item[0].SetPrice(50);
	int pokeball=1;
	
	item[1].SetName("Potion");
	item[1].SetPrice(50);
	int potion=2;
	
	//THE SUPER AND HYPER POTION INPUTS ARE STRINGS NOT LINES, THE IT WOULD NOT ACOUTN FOR THE WHITE SPACE;
	item[2].SetName("SuperPotion");
	item[2].SetPrice(100);
	int SuperPotion=3;
	
	cout<<"Welcome to the shop! What can we sell you? The options are the follwing: "<<endl;
	cout<<"1. Pokeball ($50)"<<endl;
	cout<<"2. Potion ($50)"<<endl;
	cout<<"3. SuperPotion ($100)"<<endl;
	cout<<"If you are done here simply press 0."<<endl;
	cout<<"Just a reminder you have "<< player1.GetMoney()<< " dollars"<<endl;

	cin>>opt;
	cout<<endl;	
	

	//If the player has 0 dollars then he will be sent back to the option select untill he presses 0
	if(player1.GetMoney()<=0)
	{
		cout<<"You are out of money! Go fight more trianers, or sell your pokiman."<<endl; 
		Shop(player1.GetMoney());
	}
	//We will keep asking for an input untill the player does not want to do anything else
	while(opt!=0)
	{
		if(opt == 1 )
		{
			cout<<"You have chosen a Pokibal. This item will let you catch one pokiman per ball"<<endl;
			cout<<"How many pokeballs do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(player1.GetMoney()<(item[0].GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(player1.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " Pokeball!"<<endl;
					player1.SetMoney(player1.GetMoney()-(item[0].GetPrice()*itmAmount));
				cout<<"You now have "<<player1.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm(0,itmAmount);
					Shop(player1.GetMoney());
					opt=0;
				}
		}

		
	

		if(opt == 2 )
		{
			cout<<"You have chosen a Potion. This item will let heal one of your Pokiman by 1/4 its health"<<endl;
			cout<<"How many Potions do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(player1.GetMoney()<(item[1].GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(player1.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " Potions!"<<endl;
					player1.SetMoney(player1.GetMoney()-(item[1].GetPrice()*itmAmount));
				cout<<"You now have "<<player1.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm(1,itmAmount);					
					Shop(player1.GetMoney());
					opt=0;
				}
		}
	
		if(opt == 3 )
		{
			cout<<"You have chosen a SuperPotion . This item will let you heal 1/2 your health"<<endl;
			cout<<"How many SuperPotions do you want to buy?"<<endl;
			cin >>itmAmount;
			cout<<endl;
			
			//If the price of the item is greater than amount of money that the player has, then it will send them back to the option select menu
			if(player1.GetMoney()<(item[2].GetPrice()*itmAmount))
			{
				cout<<"Sadly though, you don't have enough money! Go fight more trianers, or sell your pokiman."<<endl; 
				Shop(player1.GetMoney());
			}
			
			cout<<"Would you like to purchase "<< itmAmount << " of this item? 1 for yes, 0 for no. "<<endl;
			
			//Here we take the option to buy or not to buy
			cin>>YorN;
			cout<<endl;
				if(YorN=1)
				{
				cout<<"You bough "<< itmAmount<< " SuperPotions!"<<endl;
					player1.SetMoney(player1.GetMoney()-(item[2].GetPrice()*itmAmount));
				cout<<"You now have "<<player1.GetMoney()<<" dollars." <<endl<<endl;
					bag.AddItm(2,itmAmount);							
					Shop(player1.GetMoney());
					opt=0;
				}
		}

		
	


		
	}


}



void BattleSequence()
{
	
	int MonSel= rand()%2;
	int Rattack=rand()%2;
	Mon battleMon;
	int opt;

	cout<<"You have encounterd a wild "<< poke[MonSel].GetName()<<" !"<<endl;
	cout<<"Which Pokiman do you want to send out? "<<endl;
		battleMon=player1.MonSelect();
	cout<<"Lets go "<< battleMon.GetName()<<"!"<<endl;
	cout<<"The battle has begun!"<<endl;
	cout<<"What will "<< battleMon.GetName()<<" do?"<<endl;
	
	while(battleMon.GetHP()>=0 && poke[MonSel].GetHP()>=0)
	{
		
		cout<<"1. Attack1"<<endl;
		cout<<"2. Attack2"<<endl; 
		cout<<"3. Catch"<<endl; 
		cin>>opt;
			if(opt==1)
			{
				poke[MonSel].SetHp(poke[MonSel].GetHP()-battleMon.GetAttack1Pow());
				cout<<battleMon.GetName()<<" used "<< battleMon.GetAttack1Name()<<endl;
				cout<<"The oposing "<<poke[MonSel].GetName()<<" has taken "<<battleMon.GetAttack1Pow()<<endl;
				cout<<"The oposing "<<poke[MonSel].GetName()<<" has "<< poke[MonSel].GetHP()<< " HP"<<endl;
				cout<<endl;
					if(poke[MonSel].GetHP()<=0)
					{
						cout<<"You have defeated"<<poke[MonSel].GetName()<<endl;
						cout<<"(Press Enter to continue)"<< endl;
						cin.ignore();
						return ;
					}
				if(Rattack==1)
				{
				battleMon.SetHp(battleMon.GetHP()-poke[MonSel].GetAttack1Pow());
				cout<<poke[MonSel].GetName()<<" used "<< poke[MonSel].GetAttack1Name()<<endl;
				cout<<"The oposing "<<poke[MonSel].GetName()<<" attacked you with "<<battleMon.GetAttack1Name()<<endl;
				cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
				cout<<endl;
					
					if(battleMon.GetHP()<=0)
					{
						cout<<battleMon.GetName()<<" Has been defeated!"<<endl;
							if(player1.NoOneLeft()==0)
							{
								cout<<"You have no Pokimanleft to battle"<<endl;
								cout<<"Lets try this again."<<endl;
								return;
					
							}
						cout<<"(Press Enter to continue)"<< endl;
						cin.ignore();
						return ;
					}				
				}

					
				if(Rattack==2)
				{
				battleMon.SetHp(battleMon.GetHP()-poke[MonSel].GetAttack2Pow());
				cout<<poke[MonSel].GetName()<<" used "<< poke[MonSel].GetAttack2Name()<<endl;
				cout<<"The oposing "<<poke[MonSel].GetName()<<" attacked you with "<<battleMon.GetAttack2Pow()<<endl;
				cout<<battleMon.GetName()<<" has "<< battleMon.GetHP()<< " HP"<<endl;
				cout<<endl;
				}
			}
	}

			
}

//This fucntion will only be calle when the randomizer >=2
bool TryCatch()
{
	int Roll= rand();
	int YorN;
	Mon battleMon;
	
	
	cout<<"Lets try an catch some PokiMan!"<<endl;
	cout<<"Time to roll the Die"<<endl;
		if(Roll>=2)
		{
			cout<<"You rolled a "<< Roll<< " ! Let the battle begin."<<endl;
				BattleSequence();
				cout<<endl;
		}
		
		if(Roll<2)
		{
			cout<<"You rolled a "<<Roll<< " ! Better luck next time."<<endl;
			cout<<endl;
			
		}
}

void OptionSelect()
{
	int opt;
	

	
	cout<<"What are we doing next?"<<endl;
	cout<<"Press 1 to go to the Shop."<<endl;
	cout<<"Press 2 to go to  YourBag."<<endl;
	cout<<"Press 3 to go to Try&Catch."<<endl;
	cout<<"Press 4 to go to TrainerBattle."<<endl;
	
	
		cin>>opt;
		cout<<endl;
	
		if(opt==1)
		{
			Shop(player1.GetMoney());
			OptionSelect();	
		}		
	
		if(opt==2)
		{
		bag.InsideBag();
		OptionSelect();
		}

		if(opt==3)
		{
		TryCatch();
		OptionSelect();
		}
	
}




//This function will be called when the randomizer > 3

/*TrainerBattleSequence()
{

}
*/



int main()
{
	poke[0].SetName("Mew");
	poke[0].SetHp(100);
	poke[0].SetAttack1Name("Kick");
	poke[0].SetAttack1Pow(50);
	poke[0].SetAttack2Name("Punch");
	poke[0].SetAttack2Pow(30);

	poke[1].SetName("Mew2");
	poke[1].SetHp(100);
	poke[1].SetAttack1Name("Kick");
	poke[1].SetAttack1Pow(50);
	poke[1].SetAttack2Name("Punch");
	poke[1].SetAttack2Pow(30);	
	
	int YorN;
	int opt;
	string name;

	cout<<"Welcome to the World of Pokiman. (Press Enter to continue)"<< endl;
	cin.ignore();
	cout<< "I am profressor Benjamin Dover. I am a world known pokemaster." <<endl;
	cin.ignore();
	cout<< "I could go on and on about how awesome I am, but I want to know more about you."<< endl;
	cin.ignore();
	cout<< "First thigs first! What is your name?"<<endl;
	cin>>name;
	cout<<endl;
		player1.SetName(name);
	cout<< "Just making sure, your name is ";
		player1.GetName();
	cout<<" ?"<<endl;
	cout<< " If it's not, press 0, if it is, press 1"<<endl;
	cin>> YorN;
	cout<<endl;
	
		while(YorN== 0)
		{
			
			cout<<"Sorry, my bad, what's your name?"<<endl;
			cin>> name;
			cout<<endl;			
			player1.SetName(name);
			cout<<"Is ";
			player1.GetName();
			cout<<" correct ? 0 for no, 1 for yes"<<endl;
			cin>> YorN; 
			cout<<endl;
			
		}

	cout <<"Awesome!" <<endl;
	cout<< "Your name is ";
		player1.GetName();
	cout<<endl;
	cout<< "Now tell me, are you a boy or a girl? "<< endl;
	cout<<"If you are a boy press 1, if you are a girl, press 0."<<endl;
	
		player1.SetGender();
	
	cout<< "Just making sure, you are a ";
		if (player1.GetGender() == 1)
		{
			cout<< "boy";
		}
		else
			cout << "girl";
	cout<<" ?"<<endl;
	cout<< " If it's not true, press 0, if it is, press 1"<<endl;
	cin>> YorN;
	cout<<endl;
		while(YorN== 0)
		{
			cout<< "Sorry about that. Let's try that again "<<endl;
			cout<<" If you are a boy press 1, if your a girl press 0."<< endl;
				player1.SetGender();
				if (player1.GetGender() == 1)
			{
				cout<< "boy";
			}
				else
					cout << "girl";
			cout<<"? Is that right? 0 for no, 1 for yes."<<endl;
			cin>>YorN;
			cout<<endl;
		}
	

	cout<<"Great! Nice to meet you ";
	player1.GetName();
	cout<<" !"<<endl;
	cout<<"For you to be able to become the very best, you are goign to need a partner."<<endl;
	cout<<"Your options are the following; "<<endl;
	
	YorN=0;
	
	while(YorN==0)
	{
		cout<<"Option 1 is "<<poke[0].GetName()<<endl;
		cout<<"Option 2 is "<<poke[1].GetName()<<endl;
		cout<<"Which pokiman will will be there through your journey"<<endl;	
	
		cin>>opt;
		cout<<endl;	
		if(opt==1)
		{
			cout<<"You have chosen "<<poke[0].GetName()<<endl;
			cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				cin>>YorN;
				cout<<endl;
					if(YorN==1)
					{
						cout<<poke[0].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						player1.AddCatched(poke[0]);
					}
								
					if(YorN==0)
					{
						cout<<"Ok, not "<<poke[0].GetName()<<endl;
						
					}
				
		}

		if(opt==2)
		{
			cout<<"You have chosen "<<poke[1].GetName()<<endl;
			cout<<"Are you sure about this? 1 for yes, 0 for no. "<<endl;
				cin>>YorN;
				cout<<endl;
					if(YorN==1)
					{
						cout<<poke[1].GetName()<<" is now your new Pokiman Companion!!"<<endl;
						player1.AddCatched(poke[1]);
					}
								
					if(YorN==0)
					{
						cout<<"Ok, not " << poke[1].GetName()<<endl;
					}
		}
	}
	cout<<"Awesome! Now that you have your Pokiman, you are now able to go and andventure and become the very best!."<<endl;
	cin.ignore();
	cout<<"Time to introduce you to the Option Select menu"<<endl;
	cout<<endl;
	cout<<"What are we doing next?"<<endl;
	cout<<"Press 1 to go to the Shop."<<endl;
	cout<<"Press 2 to go to  YourBag."<<endl;
	cout<<"Press 3 to go to Try&Catch."<<endl;
	cout<<"Press 4 to go to TrainerBattle."<<endl;
	cout<<"These are goign to be the your options through out your journey."<<endl;
	cout<<endl;
	cout<<"(Press enter to continue)";	
	cin.ignore();
	cout<<endl;
	
	
	cout<<"Before anything you should go to the shop and buy some Pokiballs and potions. You wont be able to go through out your journey with out them."<<endl;
		OptionSelect();		
}
