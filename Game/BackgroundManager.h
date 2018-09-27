#pragma once

class Tile;
class Camera;
class BackgroundManager
{
public:
	BackgroundManager();
	~BackgroundManager();

	void Initialize();

	bool GetIsStopTraffic() const { return isStopTraffic; }
	void SetIsStopTraffic(bool a) { isStopTraffic = a; }

	vector<Tile*> GetTiles() const;
	Tile* GetTile(wstring name) const;
	void DeleteTiles(Camera* camera);
	void DeleteTiles(wstring name);
	void Update();
	void Render();
private:
	void AddRects();
	
	void AddForest(vector<RectDrawer*>);
	vector<Tile*>::iterator iter;
	vector<Tile*> tiles;

	bool isMove;
	bool isStopTraffic;
};