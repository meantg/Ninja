#include "Grid.h"

Grid::Grid(int mapWidth, int mapHeight)
{
	//Khởi tạo mảng cells[][] theo rows và columns dựa trên độ lớn của map
	rows = mapHeight / Cell::_cellheight;
	columns = ceil((float)(mapWidth) / Cell::_cellwidth);
	for (int y = 0; y < rows; ++y)
	{
		auto row = vector<Cell*>();
		for (int x = 0; x < columns; ++x) {
			row.push_back(new Cell(x, y));
		}
		_cells.push_back(row);
	}
	AddObject(new ESwordMan(255, 57));
	AddObject(new ESwordMan(349, 57));
	AddObject(new ESwordMan(445, 57));
	AddObject(new ESwordMan(1292, 120));
	AddObject(new ESwordMan(1452, 120));
	AddObject(new ESwordMan(1484, 140));
	AddObject(new ESwordMan(1883, 57));
	AddObject(new ESwordMan(1963, 57));

	//	//CloakMan
	//AddObject(new ECloakMan(820, 100));
	//AddObject(new ECloakMan(1230, 120));

	////	Panther
	//AddObject(new EPanther(234, 46));
	//AddObject(new EPanther(912, 118));
	//AddObject(new EPanther(945, 118));
	//AddObject(new EPanther(1281, 46));

	//	//GunMan
	/*AddObject(new EGunMan(1373, 57));*/
	/*AddObject(new EGunMan(250, 57));*/

	//	//Eagle
	AddObject(new EEagle(560, 140));
	AddObject(new EEagle(720, 140));
	AddObject(new EEagle(1060, 130));
	AddObject(new EEagle(1570, 125));
	AddObject(new EEagle(1730, 140));

	//Insert ItemHolder
		//Butterfly
	AddObject(new IHButterfly(330,80));
	AddObject(new IHButterfly(430, 80));
	AddObject(new IHButterfly(567, 80));
	AddObject(new IHButterfly(631, 104));
	AddObject(new IHButterfly(758, 121));
	AddObject(new IHButterfly(1146, 80));
	AddObject(new IHButterfly(884, 152));
	AddObject(new IHButterfly(1174, 152));
	AddObject(new IHButterfly(1321, 152));
	AddObject(new IHButterfly(1655, 80));
	AddObject(new IHButterfly(1850, 80));

	//Grounds
	AddGround(new Rect(0, 38, 540, 10));
	AddGround(new Rect(580, 42, 22, 10));
	AddGround(new Rect(644, 42, 22, 10));
	AddGround(new Rect(708, 42, 22, 10));
	AddGround(new Rect(772, 42, 22, 10));
	AddGround(new Rect(800, 73, 32, 10));
	AddGround(new Rect(836, 104, 128, 10));
	AddGround(new Rect(1026, 42, 66, 10));
	AddGround(new Rect(1125, 38, 280, 10));
	AddGround(new Rect(1409, 78, 30, 10));
	AddGround(new Rect(1440, 106, 30, 10));
	AddGround(new Rect(1470, 136, 65, 10));
	AddGround(new Rect(1603, 44, 18, 10));
	AddGround(new Rect(1665, 44, 18, 10));
	AddGround(new Rect(1729, 44, 18, 10));
	AddGround(new Rect(1800, 38, 255, 10));
	AddGround(new Rect(1213, 106, 34, 10));
	AddGround(new Rect(1280, 106, 96, 10));

	//Walls
	AddWall(new Wall(0, 160, 35, 160, 0));
	AddWall(new Wall(800, 61, 32, 32, 0));
	AddWall(new Wall(832, 91, 32, 32, 0));
	AddWall(new Wall(1410, 61, 32, 32, 0));
	AddWall(new Wall(1442, 91, 32, 32, 0));
	AddWall(new Wall(1474, 128, 32, 32, 0));
	AddWall(new Wall(2000, 170, 20, 170, 0));
}

Grid::~Grid()
{

	std::unordered_set<Object*> objs;
	std::unordered_set<Wall*> walls;
	std::unordered_set<Rect*> grounds;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			for (auto o : _cells[i][j]->objects)
			{
				objs.insert(o);
			}

			for (auto w : _cells[i][j]->walls)
			{
				walls.insert(w);
			}

			for (auto g : _cells[i][j]->grounds)
			{
				grounds.insert(g);
			}

			_cells[i][j]->objects.clear();
			_cells[i][j]->walls.clear();
			_cells[i][j]->grounds.clear();
			delete _cells[i][j];
		}
		_cells[i].clear();
	}
	_cells.clear();

	for (auto o : objs)
	{
		o = nullptr;
	}

	for (auto g : grounds)
	{
		delete g;
	}

	for (auto w : walls)
	{
		delete w;
	}
}

void Grid::AddObject(Object * obj)
{
	auto r = obj->GetRect();
	int LeftCell = r.x / Cell::_cellwidth;
	int RightCell = (r.x + r.width) / Cell::_cellwidth;
	int TopCell = r.y / Cell::_cellheight;
	int BottomCell = (r.y - r.height) / Cell::_cellheight;
	for (int y = BottomCell; y <= TopCell; ++y)
	{
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			_cells[y][x]->objects.insert(obj);
		}
	}
}

void Grid::RemoveObject(Object * obj)
{
	int LeftCell = obj->x / Cell::_cellwidth;
	int RightCell = (obj->x + obj->width) / Cell::_cellwidth;
	int TopCell = obj->y / Cell::_cellheight;
	int BottomCell = (obj->y - obj->height) / Cell::_cellheight;

	for (int y = BottomCell; y <= TopCell; ++y)
	{
		if (y < 0 || y >= rows) continue;
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			if (x < 0 || x >= columns) continue;
			else _cells[y][x]->RemoveObject(obj);
		}
	}
}

void Grid::MoveObject(Object * obj, float x, float y)
{
	if (obj->tag == ENEMY)
	{
		auto e = (Enemy*)obj;
		if (e->isOutScreen)
		{
			return;
		}
	}

	//Tính vị trí của cell cũ
	int oldLeftCell = obj->x / Cell::_cellwidth;
	int oldRightCell = (obj->x + obj->width) / Cell::_cellwidth;
	int oldTopCell = obj->y / Cell::_cellheight;
	int oldBottomCell = (obj->y - obj->height) / Cell::_cellheight;
	//Tính vị trí của cell ở vị trí mới
	int LeftCell = x / Cell::_cellwidth;
	int RightCell = (x + obj->width) / Cell::_cellwidth;
	int TopCell = y / Cell::_cellheight;
	int BottomCell = (y - obj->height) / Cell::_cellheight;
	//Cập nhật lại vị trí mới cho Object
	obj->x = x;
	obj->y = y;
	// Nếu thay đổi thì xóa obj ở cell cũ và add obj vào cell mới
	if (!(oldLeftCell < 0 || oldRightCell >= columns || oldTopCell >= rows || oldBottomCell < 0)) {
		if (LeftCell < oldLeftCell)
		{
			if (oldTopCell < rows)
			{
				_cells[oldTopCell][oldLeftCell]->RemoveObject(obj);
			}

			if (oldTopCell != oldBottomCell && oldBottomCell >= 0)
			{
				_cells[oldBottomCell][oldLeftCell]->RemoveObject(obj);
			}
		}

		if (RightCell > oldRightCell)
		{
			if (oldTopCell < rows)
			{
				_cells[oldTopCell][oldRightCell]->RemoveObject(obj);
			}

			if (oldTopCell != oldBottomCell && oldBottomCell >= 0)
			{
				_cells[oldBottomCell][oldRightCell]->RemoveObject(obj);
			}
		}

		if (TopCell < oldTopCell)
		{
			if (oldLeftCell >= 0)
			{
				_cells[oldTopCell][oldLeftCell]->RemoveObject(obj);
			}

			if (oldLeftCell != oldRightCell && oldRightCell < columns)
			{
				_cells[oldTopCell][oldRightCell]->RemoveObject(obj);
			}
		}

		if (BottomCell > oldBottomCell)
		{
			if (oldLeftCell >= 0)
			{
				_cells[oldBottomCell][oldLeftCell]->RemoveObject(obj);
			}

			if (oldLeftCell != oldRightCell && oldRightCell < columns)
			{
				_cells[oldBottomCell][oldRightCell]->RemoveObject(obj);
			}
		}


		if (TopCell < rows)
		{
			if (LeftCell >= 0)
			{
				_cells[TopCell][LeftCell]->objects.insert(obj);
			}

			if (LeftCell != RightCell && RightCell < columns)
			{
				_cells[TopCell][RightCell]->objects.insert(obj);
			}
		}

		if (BottomCell < rows)
		{
			if (LeftCell >= 0)
			{
				_cells[BottomCell][LeftCell]->objects.insert(obj);
			}

			if (LeftCell != RightCell && RightCell < columns)
			{
				_cells[BottomCell][RightCell]->objects.insert(obj);
			}
		}
	}
	
}

void Grid::Update()
{
	Rect viewport = mCamera->GetBound();
	this->UpdateVisibleCells(viewport);
	this->RespawnEnemies();
}

void Grid::UpdateVisibleCells(Rect viewport)
{
	visibleCells.clear();
	int left = viewport.x / Cell::_cellwidth;
	int right = ceil(viewport.x / Cell::_cellwidth) + 2;
	//int bottom = viewPort.y / Cell::height;
	//int top = floor(viewPort.y + viewPort.height) / Cell::height);

	for (int r = 0; r < 2; ++r)
	{
		for (int c = left; c < right; ++c)
		{
			visibleCells.push_back(_cells[r][c]);
		}
	}
}

void Grid::AddGround(Rect *g)
{
	int LeftCell = g->x / Cell::_cellwidth;
	int RightCell = (g->x + g->width) / Cell::_cellwidth;
	int TopCell = g->y / Cell::_cellheight;
	int BottomCell = (g->y - g->height) / Cell::_cellheight;
	for (int y = BottomCell; y <= TopCell; ++y)
	{
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			_cells[y][x]->grounds.push_back(g);
		}
	}
}

void Grid::AddWall(Wall * w)
{
	int LeftCell = w->wall.x / Cell::_cellwidth;
	int RightCell = (w->wall.x + w->wall.width) / Cell::_cellwidth;
	int TopCell = w->wall.y / Cell::_cellheight;
	int BottomCell = (w->wall.y - w->wall.height) / Cell::_cellheight;
	for (int y = BottomCell; y <= TopCell; ++y)
	{
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			_cells[y][x]->walls.push_back(w);
		}
	}
}

void Grid::RespawnEnemies()
{
	auto it = respawnObjects.begin();
	while (it != respawnObjects.end())
	{
		auto o = *it;
		if (o->tag == ENEMY)
		{
			auto e = (Enemy*)o;
			if (!(e->GetSpawnRect().isContain(mCamera->GetBound())))
			{
       			e->ChangeState(STANDING);
				it = respawnObjects.erase(it);
   				this->MoveObject(e, e->spawnX, e->spawnY);
				continue;
			}
		}
		++it;
	}
}

unordered_set<Object*> Grid::GetColliableObjects(Object * obj)
{
	unordered_set<Object*> objs;

	auto r = obj->GetRect();
	//Check các cell nào chứa bound của obj
	int LeftCell = r.x / Cell::_cellwidth;
	int RightCell = (r.x + r.width) / Cell::_cellwidth;
	int TopCell = r.y / Cell::_cellheight;
	int BottomCell = (r.y - r.height) / Cell::_cellheight;

	for (int y = BottomCell; y <= TopCell; ++y)
	{
		if (y < 0 || y >= rows) continue;
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			if (x < 0 || x >= columns) continue;
			//Tùy theo loại object (bullet, enemies, item) mà khởi tạo và insert vào objects
			for (auto o : _cells[y][x]->objects) {
				objs.insert(o);
			}
		}
	}
	return objs;
}

unordered_set<Wall*> Grid::GetColliableWalls(Object * obj)
{
	unordered_set<Wall*> walls;

	auto r = obj->GetRect();
	int LeftCell = r.x / Cell::_cellwidth;
	int RightCell = (r.x + r.width) / Cell::_cellwidth;
	int TopCell = r.y / Cell::_cellheight;
	int BottomCell = (r.y - r.height) / Cell::_cellheight;

	for (int y = BottomCell; y <= TopCell; ++y)
	{
		if (y < 0 || y >= rows) continue;
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			if (x < 0 || x >= columns) continue;
			for (auto w : _cells[y][x]->walls)
			{
				walls.insert(w);
			}
		}
	}
	return walls;
}

unordered_set<Rect*> Grid::GetColliableGrounds(Object * obj)
{
	unordered_set<Rect*> grounds;

	auto r = obj->GetRect();
	int LeftCell = r.x / Cell::_cellwidth;
	int RightCell = (r.x + r.width) / Cell::_cellwidth;
	int TopCell = r.y / Cell::_cellheight;
	int BottomCell = (r.y - r.height) / Cell::_cellheight;

	for (int y = BottomCell; y <= TopCell; ++y)
	{
		if (y < 0 || y >= rows) continue;
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			if (x < 0 || x >= columns) continue;
			for (auto g : _cells[y][x]->grounds)
			{
				grounds.insert(g);
			}
		}
	}
	return grounds;
}

unordered_set<Object*> Grid::GetVisibleObjects()
{
	std::unordered_set<Object*> setObjects;

	for (auto c : visibleCells)
	{
		auto it = c->objects.begin();
		while (it != c->objects.end())
		{
			auto o = *it;
			//respawn roi
			if (o->GetRect().isContain(mCamera->GetBound()))
			{
				switch (o->tag)
				{
				case ENEMY:
				{
					auto e = (Enemy*)o;
					if (e->isDead)
					{
						it = c->objects.erase(it);
						respawnObjects.insert(e);
						continue;
					}
					else if (!(e->isActive || e->isOutScreen))
					{
						e->ChangeState(RUNNING);
						e->isReverse = (player->x < e->x);
						e->vx = (e->isReverse ? -e->speed : e->speed);
					}

					if (e->isActive)
					{
						setObjects.insert(e);
					}
					break;
				}
				case WEAPON: case ITEM: case BULLET:
				{
					if (o->isDead)
					{
						it = c->objects.erase(it);
						this->RemoveObject(o);
						delete o;
						continue;
					}
					else setObjects.insert(o);
					break;
				}
				}
			}
			else //Object is out of camera
			{
				switch (o->tag)
				{
				case ENEMY:
				{
					auto e = (Enemy*)o;
					if (e->isActive)
					{
						e->isActive = false;
						it = c->objects.erase(it);
						if (e->GetSpawnRect().isContain(mCamera->GetBound()))
						{
							e->isOutScreen = true;
							respawnObjects.insert(e);
						}
						else
						{
							this->MoveObject(e, e->spawnX, e->spawnY);
						}
						continue;
					}
					break;
				}
				case ITEM: case BULLET:
				{
					it = c->objects.erase(it);
					this->RemoveObject(o);
					delete o;
					continue;
					break;
				}

				}
			}
			++it;
		}
	}

	return setObjects;			
}

unordered_set<Wall*> Grid::GetVisibleWalls()
{
	std::unordered_set<Wall*> setWalls;

	for (auto c : visibleCells)
	{
		for (auto w : c->walls)
		{
			if (w->wall.isContain(mCamera->GetBound()))
			{
				setWalls.insert(w);
			}
		}
	}
	return setWalls;
}

unordered_set<Rect*> Grid::GetVisibleGrounds()
{
	std::unordered_set<Rect*> setGrounds;

	for (auto c : visibleCells)
	{
		for (auto g : c->grounds)
		{
			if (g->isContain(mCamera->GetBound()))
			{
				setGrounds.insert(g);
			}
		}
	}
	return setGrounds;
}


//TODO: Lỗi không add được do lúc khởi tạo isActive == true, và nó nằm ngoài camera nên => Out of Camera và tự động xóa khỏi mảng
//DEAD animation cua enemy chua render du
//