#include <iostream>
#include <fstream>
using namespace std;
//-------------Classes-------------//
class LivingPerson;
class Items;
class Monster;
class Room;
class Player;
class Castle;
class Game;


//-------------Implementation of Classes-------------//

//LIVING PESON //

class LivingPerson
{

protected:
	char *name;
	bool isalive;

public:
	LivingPerson();
	LivingPerson(char*);
	~LivingPerson();
	void setisalive(bool);
	bool getIsAlive();
	char* getname();
};
LivingPerson::LivingPerson(char* n)
{
	name=new char[strlen(n)+1];
	strcpy_s(name,strlen(n)+1,n);
}
char* LivingPerson::getname()
{
	return name;
}
void LivingPerson::setisalive(bool t)
{
	isalive=t;
}
bool LivingPerson::getIsAlive()
{
	return isalive;
}
LivingPerson::LivingPerson()
{
	name=NULL;
	
	isalive=true;
}

LivingPerson::~LivingPerson()
{
	if(name!=NULL)
	{
		delete[] name;
	}
}

// ITEMS //

class Items
{
private:
	char *name;
	char *type;
	char *worth;
public:
	Items();
	Items(char*,char*,char*);
	~Items();
	char* getName();
};
char* Items::getName()
{
	return name;
}

Items::Items(char* n,char* t,char* w)
{
	name=new char[strlen(n)+1];
	strcpy_s(name,strlen(n)+1,n);

	
	type=new char[strlen(t)+1];
	strcpy_s(type,strlen(t)+1,t);

	worth=new char[strlen(w)+1];
	strcpy_s(worth,strlen(w)+1,w);

}

Items::Items()
{
	name=NULL;
	type=NULL;
	worth=NULL;
}

Items::~Items()
{
	if(name!=NULL)
	{
		delete[] name;
	}
	if(type!=NULL)
	{
		delete[] type;
	}
	if(worth!=NULL)
	{
		delete[] worth;
	}
}

// MONSTERS //

class Monster:public LivingPerson
{
private:
	Items *killedby;


public:
	Monster();
	~Monster();
	Monster(char*);
	void setKillingItem(Items*);
	Items* getKillingItem();
};
Items* Monster::getKillingItem()
{
	return killedby;
}
void Monster::setKillingItem(Items* temp)
{
	killedby=temp;
}

Monster::Monster(char *temp)
{
	name=new char[strlen(temp)+1];
	strcpy_s(name,strlen(temp)+1,temp);

	
	killedby=nullptr;
}

Monster::Monster()
{
	name=NULL;
	killedby=NULL;
}

Monster::~Monster()
{
}



// ROOM //

class Room 
{
private:
	LivingPerson *princess;
	Items *items[5];
	Monster *Monst;
	char *description;
	int  NoOfItemsInRoom;
	Room *Exits[4];
	char *ExitDir[4];
	int TotalExits;
	int exitValue;


public:
	Room();
	~Room();
	void setPrincess(LivingPerson*);
	Items* returnKillngItem();
	void setMemforExit();
	char* getn();

	void setAlive(bool );
	void PrintMonsterDesc();

	Monster* getMonster();
	
	void setExitDir(int index, char*);
	void setLockExitDir();


	void setNoOfItems(int);

	Items* getItem(int );

	bool ValidObject(Items*);
	
	Items* ReturnItem(char*);
	
	char* getDescription();
	
	void setItems(Items *);
	
	void setMonster(Monster*);
	
	void setDescription(char*);
	
	void setTotalExits(int);
	
	int getTotalExits();
	
	char* getExitDir();
    
	void setExits(int , Room*);

	void setLockExits();
	
    int getExitValue(char *);

	bool ValidDirection(char*);

	Room* getExitRoom(char *);
	int getNoOfitems();

	Items* CreateMemoryForItems(char *,char*,char*,int);

	void VanishItem(Items *temp);

	void AddItemFromBag(Items*);

	void PrintItems();


};
void Room::setPrincess(LivingPerson* p)
{
	princess=p;
}
char* Room::getn()
{
	return Monst->getname();
}
void Room::PrintMonsterDesc()
{
	if(Monst!=nullptr)
	{
		if(Monst->getIsAlive()==true)
		{
			cout<<Monst->getname()<<" is here to kill you.\n\n";
		}
		else if(Monst->getIsAlive()==false)
		{
			cout<<"Deadbody of "<<Monst->getname()<<" is lying here\n\n";
		}
	}
}
void Room::setAlive(bool t)
{
	Monst->setisalive(t);
}
Monster* Room::getMonster()
{
	return Monst;
}
Items* Room::returnKillngItem()
{
	return Monst->getKillingItem();

}
void Room::setLockExitDir()
{

}

void Room::setMonster(Monster* temp)
{
	Monst=temp;
}
int Room::getNoOfitems()
{
	return NoOfItemsInRoom;
}

void Room::PrintItems()
{
	if(NoOfItemsInRoom==1)
	{
			cout<<"The "<<items[0]->getName();
	}
	else if(NoOfItemsInRoom>1)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=NULL)
			{
				cout<<"The "<<items[i]->getName()<<", ";
			}
		}
	}
	
	
}

void Room::AddItemFromBag(Items *temp)
{
	for(int i=0;i<NoOfItemsInRoom;i++)
	{
		if(items[i]==NULL)
		{
				items[i]=temp;
		}
	}
}

void Room::VanishItem(Items *temp)
{
	for(int i=0;i<NoOfItemsInRoom;i++)
	{
		if(items[i]!=NULL)
		{
			if(items[i]==temp)
			{
				items[i]=nullptr;
				/*this->setNoOfItems(NoOfItemsInRoom-1);*/
				return;
				
			}
		}
	}

}

char* Room::getDescription()
{
	return description;
}

void Room::setMemforExit()
{
	Exits[0]=new Room;
	Exits[1]=new Room;
	Exits[2]=new Room;
	Exits[3]=new Room;

}

Items* Room::ReturnItem(char* n)
{
	if(strcmp(n,"golden egg")==0)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=nullptr)
			{
				if(strcmp(items[i]->getName(),n)==0)
				{
					return items[i];

				}
				else
				{
					cout<<"This Item is not present in this room.\n";
					
				}
				
			}
			else
			{
				cout<<"There is no item present in this room.\n";
				
			}
			
		}
		//return items[0];
	}

	else if(strcmp(n,"shield")==0)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=nullptr)
			{
				if(strcmp(items[i]->getName(),n)==0)
				{
					return items[i];
				
				}
				else
				{
					cout<<"This Item is not present in this room.\n";
					
				}
			}
			else
			{
				cout<<"There is no item present in this room.\n";
				
			}
		}
		//return items[0];
	}
	else if(strcmp(n,"chalice")==0)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=nullptr)
			{
				if(strcmp(items[i]->getName(),n)==0)
				{
					return items[i];
				
				}
				else
				{
					cout<<"This Item is not present in this room.\n";
					
				}
			}
			else
			{
				cout<<"There is no item present in this room.\n";
				
			}
		}
	}
		//return items[2];

	else if(strcmp(n,"dagger")==0)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=nullptr)
			{
				if(strcmp(items[i]->getName(),n)==0)
				{
					return items[i];
				
				}
				else
				{
					cout<<"This Item is not present in this room.\n";
					
				}
			}
			else
			{
				cout<<"There is no item present in this room.\n";
				
			}
		}
		//return items[3];
	}

	else if(strcmp(n,"notes")==0)
	{
		for(int i=0;i<NoOfItemsInRoom;i++)
		{
			if(items[i]!=nullptr)
			{
				if(strcmp(items[i]->getName(),n)==0)
				{
					return items[i];
				
				}
				else
				{
					cout<<"This Item is not present in this room.\n";
					
				}
			}
			else
			{
				cout<<"There is no item present in this room.\n";
				
			}
		}
		//return items[4];
	}
	else
		return NULL;


}

bool Room::ValidObject(Items* item)
{
	for(int i=0;i<NoOfItemsInRoom;i++)
	{
		if(items[i]!=NULL)
		{
			if(items[i]==item)
			{
				return true;
			}
		
		}

	}
	return false;
}

Items* Room::getItem(int index )
{
	return items[index];
}

void Room::setNoOfItems(int n)
{
	NoOfItemsInRoom=n;
}

void Room::setItems(Items* temp)
{

	items[NoOfItemsInRoom]=temp;
	this->NoOfItemsInRoom++;
	/*this->setNoOfItems(NoOfItemsInRoom+1);*/
}

Items* Room::CreateMemoryForItems(char * n,char* t,char* w,int index)
{

	*items=new Items[NoOfItemsInRoom];
	items[index]=new Items(n,t,w);
	return items[index];
}

Room* Room::getExitRoom(char *direction)
{
	int DirNo=this->getExitValue(direction);
	if(Exits[DirNo-1]!=nullptr)
	{
		return Exits[DirNo-1];
	}
	else
		return NULL;

}

void Room::setExitDir(int index,char *dir)
{
	ExitDir[index]=new char[strlen(dir)+1];
	strcpy_s(ExitDir[index],strlen(dir)+1,dir);
}

bool Room::ValidDirection(char *direction)
{
	for(int i=0;i<4;i++)
	{
		
		if(ExitDir[i]!=NULL)
		{
			if(strcmp(direction,ExitDir[i])==0)
			{
				return true;
			}
		}
	}
	return false;
}

int Room::getExitValue(char *direction)
{
	if(strcmp(direction,"west")==0)
	{
		return 1;
	}
	else if(strcmp(direction,"north")==0)
	{
		return 2;
	}
	else if(strcmp(direction,"east")==0)
	{
		return 3;
	}
	else if(strcmp(direction,"south")==0)
	{
		return 4;
	}
	else 
		return 0;
}

void Room::setExits(int index, Room* r)
{
	Exits[index-1]=r;
	
}
void Room::setLockExits()
{
	
	
}
	
int Room::getTotalExits()
{
	return TotalExits;
}

void Room::setTotalExits(int temp)
{
	TotalExits=temp;
}

void Room::setDescription(char* tempDesc)
{
	description=new char[strlen(tempDesc)+1];
	strcpy_s(description,strlen(tempDesc)+1,tempDesc);
}

Room::Room()
{
	for(int i=0;i<5;i++)
	{
		items[i]=nullptr;
	}

	Monst=nullptr;
	
	for(int i=0;i<4;i++)
	{
		Exits[i]=NULL;
	}

	for(int i=0;i<4;i++)
	{
		ExitDir[i]='\0';
	}

	princess=NULL;


	
	description=NULL;
	
	NoOfItemsInRoom=0;
	
	TotalExits=0;

}

Room::~Room()
{
	if(description!=NULL)
	{
		delete[] description;
	}

	for(int i=0;i<4;i++)
	{
		if(ExitDir[i]!=NULL)
		{
			delete[] ExitDir[i];
		}
	}

	
}

// PLAYER //

class Player: public LivingPerson
{
private:
	Items *Bag[10];
	bool HasPrincess;
	Room *CurrentRoom;
	char* start;
	char* endwin;
	char* endlose;

public:
	Player();
	~Player();
	Player(char*);
	void setStart(char*);
	void setEndLose(char*);
	void setEndWin(char*);
	char* getStart();
	char* getEndWin();
	char* getEndLose();
	
	bool MovePlayer( char *direction);
	void setCurrentRoom(Room *temp);
	Room* getCurrentRoom();
	bool AddItemInbag(char*);
	char* getDesc();
	bool ValidDrop(Items*);
	void vansihItemFromBag(Items*);
	void DropItemInRoom(char*);
	void look();
	Items* ReturnItemFromBag(char*);
	void Attack();
	void ReadStart();
	void ReadEndWin();
	void ReadEndLose();

};
Room* Player::getCurrentRoom()
{
	return CurrentRoom;
}
char* Player::getStart()
{
	return start;
}
char* Player::getEndWin()
{
	return endwin;
}
char* Player::getEndLose()
{
	return endlose;
}

void Player::setStart(char *temp)
{
	start=new char[strlen(temp)+1];
	strcpy_s(start,strlen(temp)+1,temp);
}
void Player::setEndLose(char *temp)
{
	endlose=new char[strlen(temp)+1];
	strcpy_s(endlose,strlen(temp)+1,temp);
}
void Player::setEndWin(char *temp)
{
	endwin=new char[strlen(temp)+1];
	strcpy_s(endwin,strlen(temp)+1,temp);
}
void Player::ReadStart()
{
	ifstream fin;
	fin.open("Start.txt");
	char buffer[500];
	while(fin.eof()==false)
	{
		fin.getline(buffer,499,EOF);
		this->setStart(buffer);
	}
	
	fin.close();
}
void Player::ReadEndWin()
{
	ifstream fin;
	fin.open("EndWin.txt");
	char buffer[200];
	while(fin.eof()==false)
	{
		fin.getline(buffer,199,EOF);
		this->setEndWin(buffer);
	}
	
	fin.close();
}
void Player::ReadEndLose()
{
	ifstream fin;
	fin.open("EndLose.txt");
	char buffer[300];
	while(fin.eof()==false)
	{
		fin.getline(buffer,299,'\n');
		this->setEndLose(buffer);
	}
	
	fin.close();
}
void Player::Attack()
{
	char *monstName;
	if((CurrentRoom->getMonster())!=nullptr)
	{
		monstName=new char[strlen(CurrentRoom->getn())+1];
		strcpy_s(monstName,strlen(CurrentRoom->getn())+1,CurrentRoom->getn());
		for(int i=0;i<10;i++)
		{
			if(Bag[i]==CurrentRoom->returnKillngItem())
			{
				CurrentRoom->setAlive(false);
				if(strcmp(monstName,"Medusa")==0)
				{
					cout<<"You have Killed Medusa. Now there is room to your south.\n\n";
					CurrentRoom->setExitDir(2,"south");
					break;
				}
				else if(strcmp(monstName,"Dracula")==0)
				{
					cout<<"\nYou have Killed Dracula. Now there is room to your south.\n\n";
					CurrentRoom->setExitDir(1,"south");
					break;
				}
			}
			else  
				cout<<"\nYou do not have the weapon to kill.\n\n";

		}
	}
	else
	{
		cout<<"\nThere is no monster in this room.\n\n";
		
	}
}
Items* Player::ReturnItemFromBag(char* n)
{
	if(strcmp(n,"golden egg")==0)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]!=nullptr)
			{
				if(strcmp(Bag[i]->getName(),n)==0)
				{
					return Bag[i];
				}
				else
				{
					cout<<"You do not have this item in your bag\n\n";
					
				}

			}
			else
				{
					cout<<"You do not have any item in your bag\n\n";
					
				}
		}
		//return items[0];
	}
	else if(strcmp(n,"shield")==0)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]!=nullptr)
			{
				if(strcmp(Bag[i]->getName(),n)==0)
				{
					return Bag[i];
				}
				else
				{
					cout<<"You do not have this item in your bag\n\n";
					
				}
			}
			else
				{
					cout<<"You do not have any item in your bag\n\n";
					
				}
		}
	}
	else if(strcmp(n,"chalice")==0)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]!=nullptr)
			{
				if(strcmp(Bag[i]->getName(),n)==0)
				{
					return Bag[i];
				}
				else
				{
					cout<<"You do not have this item in your bag\n\n";
					
				}
			}
			else
				{
					cout<<"You do not have any item in your bag\n\n";
					
				}
		}
	}

	else if(strcmp(n,"dagger")==0)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]!=nullptr)
			{
				if(strcmp(Bag[i]->getName(),n)==0)
				{
					return Bag[i];
				}
				else
				{
					cout<<"You do not have this item in your bag\n\n";
					
				}
			}
			else
				{
					cout<<"You do not have any item in your bag\n\n";
					
				}
		}
	}

	else if(strcmp(n,"notes")==0)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]!=nullptr)
			{
				if(strcmp(Bag[i]->getName(),n)==0)
				{
					return Bag[i];
				}
				else
				{
					cout<<"You do not have this item in your bag\n\n";
					
				}
			}
			else
				{
					cout<<"You do not have any item in your bag\n\n";
					
				}
		}
	}
	else
		return nullptr;




}

void Player::look()
{
	cout<<CurrentRoom->getDescription()<<"\n";
	/*cout<<"The ";*/
	CurrentRoom->PrintItems();
	cout<<" lying on the floor.\n";
	CurrentRoom->PrintMonsterDesc();
	cout<<endl;

}
void Player::DropItemInRoom(char *temp)
{
	Items* DropItem=this->ReturnItemFromBag(temp);
	if(this->ValidDrop(DropItem))
	{
		CurrentRoom->setItems(DropItem);
		this->vansihItemFromBag(DropItem);
		CurrentRoom->setNoOfItems((CurrentRoom->getNoOfitems())+1);
		cout<<DropItem->getName()<<" is succesfully dropped in this room.\n\n"; 
		
	}
		
}

void Player::vansihItemFromBag(Items*  temp)
{
	for(int i=0;i<10;i++)
	{
		if(Bag[i]!=nullptr)
		{
			if(Bag[i]==temp)
			{
				Bag[i]=nullptr;
			}
		}
	}
}

bool Player::ValidDrop(Items *temp)
{
	for(int i=0;i<10;i++)
	{
		if(Bag[i]!=nullptr)
		{
			if(Bag[i]==temp)
			{
				return true;
			}
		}
	}
	return false;
}

char* Player::getDesc()
{
	return CurrentRoom->getDescription();
}

bool Player::AddItemInbag(char* temp)
{
	Items* addItem=CurrentRoom->ReturnItem(temp);
	if(CurrentRoom->ValidObject(addItem)==true)
	{
		for(int i=0;i<10;i++)
		{
			if(Bag[i]==NULL)
			{
				Bag[i]= addItem;
				CurrentRoom->VanishItem(addItem);
				CurrentRoom->setNoOfItems((CurrentRoom->getNoOfitems())-1);
				cout<<"You have successfully added "<<addItem->getName()<<".\n\n";
				return true;
			}
		}
	}
	return false;
}

void Player::setCurrentRoom(Room *temp)
{
	CurrentRoom=temp;
}

bool Player::MovePlayer( char *direction)
{
	int DirNo=CurrentRoom->getExitValue(direction);
	if(CurrentRoom->ValidDirection(direction)==true)
	{
		this->setCurrentRoom(CurrentRoom->getExitRoom(direction));
		return true;
	}
	else
	{
		return false;
	}
}

Player::Player()
{
	for(int i=0;i<10;i++)
	{
		Bag[i]=NULL;
	}
	HasPrincess=false;
	CurrentRoom=nullptr;
	start=nullptr;
	endlose=nullptr;
	endwin=nullptr;

}

Player::Player(char* n)
{
	name=new char[strlen(n)+1];
	strcpy_s(name,strlen(n)+1,n);

	for(int i=0;i<10;i++)
	{
		Bag[i]=NULL;
	}
	start=nullptr;
	endlose=nullptr;
	endwin=nullptr;

	HasPrincess=false;
	CurrentRoom=nullptr;
}

Player::~Player()
{
	/*for(int i=0;i<10;i++)
	{
		if(Bag[i]!=NULL)
		{
			delete[] Bag[i];
		}
	}*/
	if(start!=nullptr)
		delete[] start;
	if(endwin!=nullptr)
		delete[] endwin;
	if(endlose!=nullptr)
		delete[] endlose;

}

// Castle //

class Castle
{
private:
	Room *rooms[9];

public:
	Castle();
	~Castle();
	void ReadRoomsFromFile();
	Room* ReturnRoom(int); 
	void InitializePrincess(LivingPerson*);
	void InitializeMonst(Monster**);
	void Initialize(Items ** i);
	char* get1desc();
};
void Castle::InitializePrincess(LivingPerson* p)
{
	rooms[8]->setPrincess(p);
}
char* Castle::get1desc()
{
	return rooms[0]->getDescription();
}
void Castle::InitializeMonst(Monster ** m)
{
	rooms[4]->setMonster(m[0]);
	rooms[5]->setMonster(m[1]);
}
void Castle::Initialize(Items ** i)
{

	rooms[1]->setItems(i[0]);
	rooms[2]->setItems(i[1]);
	rooms[3]->setItems(i[2]);
	rooms[6]->setItems(i[3]);
	rooms[7]->setItems(i[4]);
}
Room* Castle::ReturnRoom(int RoomNo)
{
	return rooms[RoomNo-1];
}

void Castle::ReadRoomsFromFile()
{
	ifstream fin;
	fin.open("Rooms.txt");
	char buffer[500];
	fin.ignore(19);
	for(int i=0;i<9;i++)
	{
		fin.getline(buffer,499,'\n');
		rooms[i]->setDescription(buffer);
		fin.ignore(19);
	}
	
	fin.close();
 }

Castle::Castle()
{
	rooms[0] = new Room;
	rooms[1] = new Room;
	rooms[2] = new Room;
	rooms[3] = new Room;
	rooms[4] = new Room;
	rooms[5] = new Room;
	rooms[6] = new Room;
	rooms[7] = new Room;
	rooms[8] = new Room;

	rooms[0]->setMemforExit();
	rooms[1]->setMemforExit();
	rooms[2]->setMemforExit();
	rooms[3]->setMemforExit();
	rooms[4]->setMemforExit();
	rooms[5]->setMemforExit();
	rooms[6]->setMemforExit();
	rooms[7]->setMemforExit();
	rooms[8]->setMemforExit();

	rooms[0]->setExitDir(0, "east"); 
	rooms[0]->setExitDir(1, "south");
	rooms[1]->setExitDir(0,  "west");
	rooms[1]->setExitDir(1,  "east");
	rooms[1]->setExitDir(2,  "south");
	rooms[2]->setExitDir(0, "west");
	rooms[3]->setExitDir(0,  "north");
	rooms[4]->setExitDir(0, "north");
	rooms[4]->setExitDir(1, "east");
	/*rooms[4]->setExitDir(2, "south");*/
	rooms[5]->setExitDir(0,  "west");
	/*rooms[5]->setExitDir(1, "south");*/
	rooms[6]->setExitDir(0, "east");
	rooms[7]->setExitDir(0,  "west");
	rooms[7]->setExitDir(1, "north");
	rooms[8]->setExitDir(0, "north");
	
	rooms[0]->setExits(3, rooms[1]);
	rooms[0]->setExits(4, rooms[3]);
	rooms[1]->setExits(1, rooms[0]);
	rooms[1]->setExits(3, rooms[2]);
	rooms[1]->setExits(4, rooms[4]);
	rooms[2]->setExits(1, rooms[1]);
	rooms[3]->setExits(2, rooms[0]);
	rooms[4]->setExits(2, rooms[1]);
	rooms[4]->setExits(3, rooms[5]);
	rooms[4]->setExits(4, rooms[7]);
	rooms[5]->setExits(1, rooms[4]);
	rooms[5]->setExits(4, rooms[8]);
	rooms[6]->setExits(3, rooms[7]);
	rooms[7]->setExits(1, rooms[6]);
	rooms[7]->setExits(2, rooms[4]);
	rooms[8]->setExits(2, rooms[5]);
}

Castle::~Castle()
{
	for (int i=0; i < 9;i++)
		delete rooms[i];

}

// GAME //
 
class Game 
{
private:
	LivingPerson *Princess;
	Castle *castle;
	//Room *rooms[9];
	Player *user;
	Monster *monst[2];
	Items *items[5];
 public:
	Game();
	~Game();
	bool RescuePrincess();
	void setGame();
	void ReadStart();
	void play();
};
bool Game::RescuePrincess()
{
	Room* cr=user->getCurrentRoom();
	Room* room9=castle->ReturnRoom(9);
	if(cr==room9)
	{
		return true;
	}
	return false;
}
void Game::setGame()
{
	castle= new Castle;
	castle->ReadRoomsFromFile();
	user->setCurrentRoom(castle->ReturnRoom(1));
	items[0]= new Items("golden egg","T","$500,000");
	items[1]= new Items("shield","W","$0");
	items[2]= new Items("chalice","T","$500,000");
	items[3]= new Items("dagger","W","$0");
	items[4]= new Items("notes","T","$1,000,000");
	monst[0]=new Monster("Medusa");
	monst[0]->setKillingItem(items[1]);
	monst[1]=new Monster("Dracula");
	monst[1]->setKillingItem(items[3]);
	Princess=new LivingPerson("Princess");
	castle->Initialize(items);
	castle->InitializeMonst(monst);
	castle->InitializePrincess(Princess);
	user->ReadStart();
	user->ReadEndWin();
	user->ReadEndLose();
}

Game::Game()
{
	
	castle=NULL;
	user= new Player("Prince");
	for(int i=0;i<2;i++)
	{
		monst[i]=NULL;
	}

	for(int i=0;i<5;i++)
	{
		items[i]=NULL;
	}


}

void Game::play()
{
	
	setGame();
	cout<<"\t\t------GAME------"<<user->getStart()<<endl<<endl;
	cout<<endl<<castle->get1desc();
	char command[10]="\0", d[7]="\0",o[15]="\0",r[15]="\0";
	cout<<"\n\nmove, pick, drop, attack and look commands are valid. Use lower case characters for commands.\n\n"<<"Enter Command: \t";
	cin.getline(command,10);
	while(strcmp(command,"exit")!=0)
	{
		if(strcmp(command,"move")==0)
		{
			cout<<"Direction: \t";
		    cin.getline(d,6);
			if(user->MovePlayer(d)==true)
			{
				cout<<endl<<user->getDesc()<<endl<<endl;
				if(RescuePrincess()==true)
				{
					cout<<user->getEndWin();
					break;
				}
			}
		    else 
		    {
			    cout<<"Invalid Command\n\n";
			}
		}
		else if(strcmp(command,"pick")==0)
		{
			cout<<"Object: \t";
		    cin.getline(o,14);
		    if(user->AddItemInbag(o)==false)
			{
				cout<<endl<<"INVALID COMMAND!\n\n";
			}
		}
		    
		else if(strcmp(command,"drop")==0)
		{
			cout<<"enter the object \t";
		    cin.getline(r,14);
			user->DropItemInRoom(r);
		}
		else if(strcmp(command,"look")==0)
		{
			user->look();
		}
		else if(strcmp(command,"attack")==0)
		{
			user->Attack();
		}
		else
			cout<<"INVALID COMMAND!\n\n";

		cout<<"Enter Command: \t";
		cin.getline(command,10);

	}
}

Game::~Game()
{
	for(int i=0;i<2;i++)
	{
		if(monst[i]!=NULL)
		{
			delete monst[i];
		}
	}
	for(int i=0;i<5;i++)
	{
		if(items[i]!=NULL)
		{
			delete items[i];
		}
	}
	delete user;
	delete castle;
	delete Princess;

}
void main()
{
	Game *game;
	game=new Game;
	game->play();
	delete game;
	system("pause");
}
