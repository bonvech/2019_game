/**
@file map.h
\author Aglaya
\brief Класс карты
*/
class Map
{
private:
    HDC map_pic;
    int n, m;
    int loc[8][10];

    /**
    \brief
    */
public:
    Map(); // constructor
    ~Map();// destructor
    void Draw();
    int  Get_cell(int x, int y);
    void Set_cell(int i, int j, int type);
};


Map::Map()
{
    n = 7;
    m = 10;
    int l[7][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 2, 0, 0, 0, 0, 1, 1, 1, 0},
                    {0, 1, 0, 0, 1, 1, 1, 0, 1, 0},
                    {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}};
    map_pic = txLoadImage("map_aglaya.bmp");

    int i, j;
    for(i = 0; i < n; i += 1)
        for(j = 0; j < m; j += 1)
            loc[i][j] = l[i][j];
    printf("Hello!===============================\n");
}


void Map::Draw()
{
    int i, j;
    for(i = 0; i < n; i += 1)
    {
        for(j = 0; j < m; j += 1)
        {
            txTransparentBlt(txDC(), j*80, i*60, 100, 85, map_pic, 214, 82, TX_WHITE);
            if(loc[i][j] == 1)
            {
                txTransparentBlt(txDC(), j*80, i*60, 100, 85, map_pic, 85, 82, TX_WHITE);
            }
            if(loc[i][j] == 2)
            {
                txTransparentBlt(txDC(), j*80, i*60, 100, 85, map_pic, 330, 108, TX_WHITE);
            }
        }
    }

}


// destructor
Map::~Map()
{
     txDeleteDC(map_pic);
     printf("Bye!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}

int  Map::Get_cell(int x, int y)
{
    int i = (y + 90) / 53;
    int j = (x+ 22) / 80;
    return loc[i-1][j];
}

void Map::Set_cell(int x, int y, int type)
{
    loc[x / n][y / m] = type;
}
