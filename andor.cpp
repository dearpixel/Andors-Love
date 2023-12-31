/*
TODO:
1. map render

не забыть, что игровые файлы в другой папке

toolate:
1. Таблички можно ставить, забирать и переписывать
2. Специализация: призыватель, лучник, мечник, копейщик, маг, ниндзя...
3. Раса: человек, дворф, орк, ящер, эльф...
4. СУНДУКИ! toolate...
5. Можно ставить, соединять и убирать порталы (только после выполнения непростого квеста в статы записывается скилл "Мастер нулевой точки"). Порталы можно купить у торговца, который выдал квест. Квест открывается с 20лвл
6. ЗАЧАРОВАНИЯ!
7. Радиус обнаружения (противник начинает преследование, и даже выходит из зоны своего спавна, но всё еще считается её участником, а если игрок ушёл на расстояние, равное 2 радиусам обнаружения, то противник возвращается в свою зону спавна). для этого нужно применить алгоритм поиска пути
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

//base functions
void WriteAllLines(string path, vector<string> txt)
{
  char tc[80];
  FILE *fp=fopen(path.c_str(),"w");
  for (int i = 0; i < txt.size(); i++)
  {
    sprintf(tc,"%s",txt[i].c_str());
    fputs(tc,fp);fputs("\n",fp);
  }
  fclose(fp);
}

vector<string> ReadAllLines(string path)
{
  vector<string> res;
  FILE *fp;
  if ((fp = fopen(path.c_str(),"r")) == NULL)
  {
    fclose(fp);
    return res;
  } else fp = fopen(path.c_str(),"r");
  string line;
  char ch;
  while (!feof(fp))
  {
    ch = getc(fp);
    if (ch == '\n')
    {
      res.push_back(line);
      line = "";
    } else line += ch;
  }
  fclose(fp);
  return res;
}

#include <sstream>
template <typename T>
std::string toString(T val)
{
  std::ostringstream oss;
  oss<<val;
  return oss.str();
}
void print(string line) {
    cout << line << endl;
}
int select(string title, vector<string> choices) {
    int select = -1;
    print(title);
    for (int i = 0; i < choices.size(); i++)
      print(toString(i+1)+". "+choices[i]);
    char ch = 0;
    while (ch < 49 || ch > 48+choices.size()) {
        ch = getch();
    }
    select = ch-49;
    return select;
}
string question(string title) {
    system("clear");
    print(title);
    string answer;
    cin >> answer;
    return answer;
}

//dataset
    vector<string> mline;
struct player {
    //non-combat stats
    string name = "test";
    int level, exp, maxexp, location, x, y = 0;
    //base stats
    int _hp, _ap, _dmg, _dmg_chance, _dmg_cost, _reequip_cost, _use_cost, _move_cost, _block_chance, _resist = 0;
    //combat stats = base + skills + equipment
    int hp, ap, dmg, dmg_chance, dmg_cost, reequip_cost, use_cost, move_cost, block_chance, resist = 0;
    void set_start(string new_name) {
        new_name = name;
        level = 1;
        exp = 1;
        maxexp = 55;
        location = 0;
        x = 1;
        y = 4;
        _hp = 25;
        _ap = 10;
        _dmg = 1;
        _dmg_chance = 60;
        _dmg_cost = 5;
        _reequip_cost = 5;
        _use_cost = 5;
        _move_cost = 6;
        _block_chance = 0;
        _resist = 0;
    }
    void load_char() {
        
    }
};

struct enemy {
    string name;
    int hp, ap, money, location, x, y;
};

struct base_map {
    int width,height = 0;
    vector<int> cells;
    void load_map(int location) {
        mline = ReadAllLines("map/"+toString(location)+".txt");
        for (int i = 0; i < mline.size(); i++);
        //здесь чтение карты
    }
};
player plr;
enemy enm;
base_map map; //базовая локация 0 1
base_map amap; //актуальная локация, высчитывается перед каждым действием, по ней мобы понимают где что, она же рендерится

//gameplay functions
void render_map() {
    
}

void render() {
   system("clear");
   render_map();
}
void update() {
    while(1);
}

//gamesetup functions
void create() {
    plr.set_start(question("Выберите имя"));
    map.load_map(plr.location);
}

void load() {
    plr.load_char();
    map.load_map(plr.location);
}

void gameplay() {
    while (1) { //убрать вечный цикл
        render();
        update();
    }
}

int main() {
	while (1) {
	    mline.clear();
	    mline.push_back("Новая игра");
  	  mline.push_back("Загрузить");
  	  mline.push_back("Справка");
 	   mline.push_back("Выход");
	    system("clear");
	    switch (select("Любовь Эндора\nГлавное меню",mline)) {
	        case 0: create(); gameplay(); break;
	        case 1: load(); gameplay(); break;
	        case 2: return(0);
	    }
	}
}
}
