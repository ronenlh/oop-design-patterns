#include <map>
#include <vector>
using namespace std;

enum Direction {North, South, East, West};

class MapSite 
{
public:
	virtual void Enter() = 0;
};

class Room : public MapSite 
{
public:
	Room(int roomNo);

	MapSite* GetSide(Direction) const;
	void SetSide(Direction d, MapSite* m) 
	{
		_sides.insert(pair<Direction, MapSite*>(d,m));					
	}

	virtual void Enter();

private:
	map<Direction, MapSite*> _sides;
	int _roomNumber;
};

class Wall : public MapSite
{
public:
	Wall();

	virtual void Enter();
};

class Door : public MapSite
{
public:
	Door(Room* = nullptr, Room* = nullptr);

	virtual void Enter();
	Room* OtherSideFrom(Room*);

private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;	
};

class Maze
{
public:
	Maze();

	void AddRoom(Room* r)
	{
		_rooms.push_back(r);
	}
	Room* RoomNo(int) const;

private:
	vector<Room*> _rooms;
};

