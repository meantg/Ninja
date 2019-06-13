#include "Grid.h"

Grid::Grid(int mapWidth, int mapHeight)
{
	//Khởi tạo mảng cells[][] theo rows và columns dựa trên độ lớn của map
	rows = mapHeight / Cell::_cellheight;
	columns = mapWidth / Cell::_cellwidth;
	for (int y = 0; y < rows; ++y)
	{
		auto row = vector<Cell*>();
		for (int x = 0; x < columns; ++x) {
			row.push_back(new Cell(x, y));
		}
		_cells.push_back(row);
	}
}

void Grid::AddObject(Object * obj)
{
	int LeftCell = obj->x / Cell::_cellwidth;
	int RightCell = (obj->x + obj->width) / Cell::_cellwidth;
	int TopCell = obj->y / Cell::_cellheight;
	int BottomCell = (obj->y - obj->height) / Cell::_cellheight;
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
	// Nếu ở vị trí cũ thì không thay đổi gì
	if (oldLeftCell == LeftCell && oldRightCell == RightCell && oldTopCell == TopCell && oldBottomCell == BottomCell) {
		return;
	}
	// Nếu thay đổi thì xóa obj ở cell cũ và add obj vào cell mới
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

unordered_set<Object*> Grid::GetColliableObjects(Object * obj)
{
	unordered_set<Object*> objs;

	auto r = obj->GetRect();
	//Check các cell nào chứa bound của obj
	int LeftCell = r.left / Cell::_cellwidth;
	int RightCell = r.right / Cell::_cellwidth;
	int TopCell = r.top / Cell::_cellheight;
	int BottomCell = r.bottom / Cell::_cellheight;
	for (int y = BottomCell; y <= TopCell; ++y)
	{
		if (y < 0 || y >= rows) continue;
		for (int x = LeftCell; x <= RightCell; ++x)
		{
			if (x < 0 || x >= columns) continue;
			//Tùy theo loại object (bullet, enemies, item) mà khởi tạo và insert vào objects
		}
	}
}

unordered_set<Wall*> Grid::GetColliableWalls(Object * obj)
{
	unordered_set<Wall*> walls;

	auto r = obj->GetRect();
	int LeftCell = r.left / Cell::_cellwidth;
	int RightCell = r.right / Cell::_cellwidth;
	int TopCell = r.top / Cell::_cellheight;
	int BottomCell = r.bottom / Cell::_cellheight;

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

unordered_set<Ground*> Grid::GetColliableGrounds(Object * obj)
{
	unordered_set<Ground*> grounds;

	auto r = obj->GetRect();
	int LeftCell = r.left / Cell::_cellwidth;
	int RightCell = r.right / Cell::_cellwidth;
	int TopCell = r.top / Cell::_cellheight;
	int BottomCell = r.bottom / Cell::_cellheight;

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
	return unordered_set<Object*>();
}

unordered_set<Wall*> Grid::GetVisibleWalls()
{
	return unordered_set<Wall*>();
}

unordered_set<Ground*> Grid::GetVisibleGrounds()
{
	return unordered_set<Ground*>();
}


