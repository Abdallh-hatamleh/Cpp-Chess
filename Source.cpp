#include<iostream>
#include<string>

using std::string;
string Die[8] = { "N","S","E","W","NE","NW","SE","SW" };

int northern = 1;
int southern = 2;
int eastern = 3;
int western = 4;
int northeastern = 5;
int northwestern = 6;
int southeastern = 7;
int southwestern = 8;
int* up = &northern;
int* down = &southern;
int* right = &eastern;
int* left = &western;
int* upright = &northeastern;
int* upleft = &northwestern;
int* downright = &southeastern;
int* downleft = &southwestern;
const char* Positions[64] = { "000","000","000","000","000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" ,"000" };
int turn = 1;
bool gameover = 0;
void draw();




const char* chkXY(int x, int y)
{
    for (int i = 1; i <= 8; i++)
    {
        if (x == i)
        {
            for (int r = 1; r <= 8; r++)
            {
                if (y == r)
                {
                    for (int u = 0; u < 8; u++)
                    {
                        if (i == u + 1)
                            return Positions[r - 1 + (8 * u)];
                    }
                }
            }
        }
    }
}
int chkpic(const char* mess)
{
    for (int z = 0; z < 64; z++)
    {
        if (Positions[z] == mess)
            return z;
    }
}



class Piece
{
protected:
    int curY;
    int curX;
    bool alive;
    const char* name;
    bool team;
public:
    virtual void movep()
    {
        int futureX, futureY;

    };
    void Position()
    {
        std::cout << "X = " << curX << " Y = " << curY << std::endl;
    }
    void sortloop()
    {
        for (int z = 0; z < 64; z++)
        {
            if (Positions[z] == name)
                Positions[z] = "000";
        }
        for (int i = 1; i <= 8; i++)
        {
            if (curX == i)
            {
                for (int r = 1; r <= 8; r++)
                {
                    if (curY == r)
                    {
                        for (int u = 0; u < 8; u++)
                        {
                            if (i == u + 1)
                                Positions[r - 1 + (8 * u)] = name;
                        }
                    }
                }
            }
        }
    }
    friend void sortloop(Piece& t)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (t.curX == i)
            {
                for (int r = 1; r <= 8; r++)
                {
                    if (t.curY == r)
                    {
                        for (int u = 0; u < 8; u++)
                        {
                            if (i == u + 1)
                                Positions[r - 1 + (8 * u)] = t.name;
                        }
                    }
                }
            }
        }
    }

    virtual void chkmov(int FX, int FY) {
        if ((chkXY(FX, FY) == "B1" || chkXY(FX, FY) == "B2" || chkXY(FX, FY) == "B3" || chkXY(FX, FY) == "B4" || chkXY(FX, FY) == "B5" || chkXY(FX, FY) == "B6" || chkXY(FX, FY) == "B7" || chkXY(FX, FY) == "B8" || chkXY(FX, FY) == "BK1" || chkXY(FX, FY) == "BK2" || chkXY(FX, FY) == "BB1" || chkXY(FX, FY) == "BB2" || chkXY(FX, FY) == "BR1" || chkXY(FX, FY) == "BR2" || chkXY(FX, FY) == "BQ0" || chkXY(FX, FY) == "BKGG"))
        {
            if ((team == 1) && turn % 2 == 1)
                std::cout << "[ERROR:] This move is not permitted" << std::endl;
            else if ((team == 0) && turn % 2 == 0) {
                std::cout << chkXY(curX, curY) << " Killed " << chkXY(FX, FY) << std::endl;
                curX = FX;
                curY = FY;
                sortloop();
                draw();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
            }
            else std::cout << "Can't move other team's pieces" << std::endl;

        }
        else if ((chkXY(FX, FY) == "WP1" || chkXY(FX, FY) == "WP2" || chkXY(FX, FY) == "WP3" || chkXY(FX, FY) == "WP4" || chkXY(FX, FY) == "WP5" || chkXY(FX, FY) == "WP6" || chkXY(FX, FY) == "WP7" || chkXY(FX, FY) == "WP8" || chkXY(FX, FY) == "WK1" || chkXY(FX, FY) == "WK2" || chkXY(FX, FY) == "WB1" || chkXY(FX, FY) == "WB2" || chkXY(FX, FY) == "WR1" || chkXY(FX, FY) == "WR2" || chkXY(FX, FY) == "WQ0" || chkXY(FX, FY) == "WKG"))
        {
            if (team == 1 && turn % 2 == 1) {
                std::cout << chkXY(curX, curY) << " Killed " << chkXY(FX, FY) << std::endl;
                curX = FX;
                curY = FY;
                sortloop();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
                draw();
            }
            if (team == 0 && turn % 2 == 0)
                std::cout << "[ERROR:] Can't move on allied pieces" << std::endl;
            else std::cout << "Can't move other team's pieces" << std::endl;
        }
        else if (team == 1 && turn % 2 == 1) {
            curX = FX;
            curY = FY;
            sortloop();
            draw();
            std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
        }
        else if (team == 0 && turn % 2 == 0)
        {
            curX = FX;
            curY = FY;
            sortloop();
            draw();
            std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;

        }
        else std::cout << "Can't move other team's pieces" << std::endl;
    }


    int chkpic()
    {
        for (int z = 0; z < 64; z++)
        {
            if (Positions[z] == name)
                return z;
        }
    }
    bool chkmovB(int FX, int FY) {
        if (chkXY(FX, FY) == "000")
            return 1;
        else
            return 0;
    }
    bool chkp1(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FX--;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp2(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FX++;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp3(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY--;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp4(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY++;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp5(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY--;
            FX--;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp6(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY++;
            FX--;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp7(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY--;
            FX++;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
    bool chkp8(int FX, int FY, int am)
    {
        bool q[7] = { 1,1,1,1,1,1,1 };
        while (am > 0)
        {
            am--;
            FY++;
            FX++;
            q[am] = chkmovB(FX, FY);
        }
        if (q[1] && q[2] && q[3] && q[4] && q[5] && q[6])
            return 1;
        else
            return 0;
    }
};
class King : public Piece
{
public:

    King(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        team = t;
        sortloop();
    }
    void  movep(int* direction)
    {

        int futureX = curX, futureY = curY;
        switch (*direction)
        {
        case 1: futureX++;
            break;
        case 2: futureX--;
            break;
        case 3: futureY++;
            break;
        case 4: futureY--;
            break;
        case 5: futureX++, futureY++;
            break;
        case 6: futureX++, futureY--;
            break;
        case 7: futureX--, futureY++;
            break;
        case 8: futureX--, futureY--;
            break;
        default: break;
        }
        chkmov(futureX, futureY);



    }
};
class Queen : public Piece
{
public:
    Queen(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        sortloop();
        team = t;

    }
    void movep(int* direction, int amount)
    {
        int futureX = curX, futureY = curY;
        bool a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1;
        switch (*direction)
        {
        case 1: futureX += amount, a = chkp1(futureX, futureY, amount);
            break;
        case 2: futureX -= amount, b = chkp2(futureX, futureY, amount);
            break;
        case 3: futureY += amount, c = chkp3(futureX, futureY, amount);
            break;
        case 4: futureY -= amount, d = chkp4(futureX, futureY, amount);
            break;
        case 5: futureX += amount, futureY += amount, e = chkp5(futureX, futureY, amount);
            break;
        case 6: futureX += amount, futureY -= amount, f = chkp6(futureX, futureY, amount);
            break;
        case 7: futureX -= amount, futureY += amount, g = chkp7(futureX, futureY, amount);
            break;
        case 8: futureX -= amount, futureY -= amount, g = chkp8(futureX, futureY, amount);
            break;
        default:std::cout << "where are you going silly ?";
        }
        if (a && b && c && d && e && f && g && h)
            chkmov(futureX, futureY);
        else
            std::cout << "[ERROR:] Piece in the way" << std::endl;
    }
};
class Bishop : public Piece
{
public:
    Bishop(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        sortloop();
        team = t;
    }
    void movep(int* direction, int amount)
    {
        bool a = 1, b = 1, c = 1, d = 1;
        int futureX = curX, futureY = curY;
        switch (*direction)
        {
        case 5: futureX += amount, futureY += amount, a = chkp5(futureX, futureY, amount);
            break;
        case 6: futureX += amount, futureY -= amount, b = chkp6(futureX, futureY, amount);
            break;
        case 7: futureX -= amount, futureY += amount, c = chkp7(futureX, futureY, amount);
            break;
        case 8: futureX -= amount, futureY -= amount, d = chkp8(futureX, futureY, amount);
            break;
        default:std::cout << "where are you going silly ?";
        }
        if (a && b && c && d)
            chkmov(futureX, futureY);
        else
            std::cout << "[ERROR:] Piece in the way" << std::endl;
    }
};
class Rook : public Piece
{
public:
    Rook(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        sortloop();
        team = t;
    }

    void movep(int* direction, int amount)
    {
        int futureX = curX, futureY = curY;
        bool a = 1, b = 1, c = 1, d = 1;
        switch (*direction)
        {
        case 1: futureX += amount, a = chkp1(futureX, futureY, amount);
            break;
        case 2: futureX -= amount, b = chkp2(futureX, futureY, amount);
            break;
        case 3: futureY += amount, c = chkp3(futureX, futureY, amount);
            break;
        case 4: futureY -= amount, d = chkp4(futureX, futureY, amount);
            break;
        default:std::cout << "where are you going silly ?";
        }
        if (a && b && d && c)
            chkmov(futureX, futureY);
        else
            std::cout << "[ERROR:] Piece in the way" << std::endl;
    }
};

class Pawn : public Piece
{
public:
    Pawn(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        sortloop();
        team = t;
    }
    void chkmov(int FX, int FY) {
        if (chkXY(FX, FY) == "000")
        {
            if (team == 1 && turn % 2 == 1) {
                curX = FX;
                curY = FY;
                sortloop();
                draw();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
            }
            else if (team == 0 && turn % 2 == 0)
            {
                curX = FX;
                curY = FY;
                sortloop();
                draw();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
            }
            else std::cout << "Can't move other team's pieces" << std::endl;
        }
        else std::cout << "pawns can't move on top of other units" << std::endl;
    }
    void chkmovK(int FX, int FY) {
        if ((chkXY(FX, FY) == "BP1" || chkXY(FX, FY) == "BP2" || chkXY(FX, FY) == "BP3" || chkXY(FX, FY) == "BP4" || chkXY(FX, FY) == "BP5" || chkXY(FX, FY) == "BP6" || chkXY(FX, FY) == "BP7" || chkXY(FX, FY) == "BP8" || chkXY(FX, FY) == "BK1" || chkXY(FX, FY) == "BK2" || chkXY(FX, FY) == "BB1" || chkXY(FX, FY) == "BB2" || chkXY(FX, FY) == "BR1" || chkXY(FX, FY) == "BR2" || chkXY(FX, FY) == "BQ0" || chkXY(FX, FY) == "BKG"))
        {
            if (team == 1 && turn % 2 == 1)
                std::cout << "[ERROR:] Can't Kill allied pieces" << std::endl;
            if (team == 0 && turn % 2 == 0) {
                std::cout << chkXY(curX, curY) << " Killed " << chkXY(FX, FY) << std::endl;
                curX = FX;
                curY = FY;
                sortloop();
                draw();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
            }
            else std::cout << "Can't move other team's pieces" << std::endl;

        }
        else if ((chkXY(FX, FY) == "WP1" || chkXY(FX, FY) == "WP2" || chkXY(FX, FY) == "WP3" || chkXY(FX, FY) == "WP4" || chkXY(FX, FY) == "WP5" || chkXY(FX, FY) == "WP6" || chkXY(FX, FY) == "WP7" || chkXY(FX, FY) == "WP8" || chkXY(FX, FY) == "WK1" || chkXY(FX, FY) == "WK2" || chkXY(FX, FY) == "WB1" || chkXY(FX, FY) == "WB2" || chkXY(FX, FY) == "WR1" || chkXY(FX, FY) == "WR2" || chkXY(FX, FY) == "WQ0" || chkXY(FX, FY) == "WKG"))
        {
            if (team == 1 && turn % 2 == 1) {
                std::cout << chkXY(curX, curY) << " Killed " << chkXY(FX, FY) << std::endl;
                curX = FX;
                curY = FY;
                sortloop();
                draw();
                std::cout << chkXY(curX, curY) << " moved to " << chkpic() << std::endl;
            }
            if (team == 0 && turn % 2 == 0)
                std::cout << "[ERROR:] Can't Kill allied pieces" << std::endl;
            else std::cout << "Can't move other team's pieces" << std::endl;
        }
        else {
            std::cout << "[ERROR:] This move is not permitted" << std::endl;
        }
    }
    void movep()
    {
        int futureX = curX, futureY = curY;
        if (team == 1) {
            futureX--;
        }
        if (team == 0) {
            futureX++;
        }
        chkmov(futureX, futureY);
    };
    void kill(int* direction)
    {
        int futureX = curX, futureY = curY;
        if (team == 1) {
            if (*direction == 3) {
                futureY++;
                futureX--;
            }
            else if (*direction == 4) {
                futureY--;
                futureX++;
            }
        }
        if (team == 0) {
            if (*direction == 3)
            {
                futureY++;
                futureX++;
            }
            if (*direction == 4)
            {
                futureY--;
                futureX++;
            }
        }
        chkmovK(futureX, futureY);
    }

    void Dmovep()
    {
        int futureX = curX, futureY = curY;
        bool a = 1, b = 1;
        if (team == 1 && curX == 7)
        {
            futureX -= 2;
            a = chkp2(futureX, futureY, 2);
        }
        else if (team == 0 && curX == 2)
        {
            futureX += 2;
            b = chkp1(futureX, futureY, 2);
        }
        if (a && b)
            chkmov(futureX, futureY);
        else std::cout << "piece is not in the right place to do this move" << std::endl;
    }
};
class Knight : public Piece
{
public:
    Knight(int x, int y, const char* mess, bool t)
    {
        alive = 1;
        curX = x;
        curY = y;
        name = mess;
        sortloop();
        team = t;
    }
    void movep(int* direction)
    {
        int futureX = curX, futureY = curY;
        switch (*direction)
        {

        case 1: futureX += 2, futureY += 1;
            break;
        case 2: futureX -= 2, futureY -= 1;
            break;
        case 3: futureX -= 1, futureY += 2;
            break;
        case 4: futureX += 1, futureY -= 2;
            break;
        case 5: futureX += 1, futureY += 2;
            break;
        case 6: futureX += 2, futureY += 1;
            break;
        case 7: futureX -= 2, futureY += 1;
            break;
        case 8: futureX -= 1, futureY -= 2;
            break;
        default:std::cout << "where are you going silly ?";
        }
        chkmov(futureX, futureY);
    }
};
int  main()
{
    //White team:

    King WKG(1, 5, "WKG", 0);
    Queen WQ0(1, 4, "WQ0", 0);
    Bishop WB1(1, 3, "WB1", 0);
    Bishop WB2(1, 6, "WB2", 0);
    Rook WR1(1, 1, "WR1", 0);
    Rook WR2(1, 8, "WR2", 0);
    Knight WK1(1, 2, "WK1", 0);
    Knight WK2(1, 7, "WK2", 0);
    Pawn WP1(2, 1, "WP1", 0);
    Pawn WP2(2, 2, "WP2", 0);
    Pawn WP3(2, 3, "WP3", 0);
    Pawn WP4(2, 4, "WP4", 0);
    Pawn WP5(2, 5, "WP5", 0);
    Pawn WP6(2, 6, "WP6", 0);
    Pawn WP7(2, 7, "WP7", 0);
    Pawn WP8(2, 8, "WP8", 0);
    //Black team:

    King BKG(8, 5, "BKG", 1);
    Queen BQ0(8, 4, "BQ0", 1);
    Bishop BB1(8, 3, "BB1", 1);
    Bishop BB2(8, 6, "BB2", 1);
    Rook BR1(8, 1, "BR1", 1);
    Rook BR2(8, 8, "BR2", 1);
    Knight BK1(8, 2, "BK1", 1);
    Knight BK2(8, 7, "BK2", 1);
    Pawn BP1(7, 1, "BP1", 1);
    Pawn BP2(7, 2, "BP2", 1);
    Pawn BP3(7, 3, "BP3", 1);
    Pawn BP4(7, 4, "BP4", 1);
    Pawn BP5(7, 5, "BP5", 1);
    Pawn BP6(7, 6, "BP6", 1);
    Pawn BP7(7, 7, "BP7", 1);
    Pawn BP8(7, 8, "BP8", 1);
    draw();
 

    while (!gameover)
    {
        int enteredamount;
        string piece_N;
        string Path;
        char special = 'a';
        std::cin >> piece_N >> enteredamount >> Path >> special;     
        if (piece_N == "help")
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "This page will explain all the commands needed to play the game" << std::endl;
            std::cout << "Typing commands should be in the following order" << std::endl;
            std::cout << "Piecename (amount Of Movement) (Direction of movement) special" << std::endl;
            std::cout << "if the chosen piece can only move in a certain way then direction or/and amount don't matter" << std::endl;
            std::cout << "special is only for moving pawns twice up or killing with them" << std::endl;
            std::cout << "Type commands if you want to see exactly how to fill each field" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        else if (piece_N == "commands")
        {
            std::cout << "Piece names:" << std::endl;
            std::cout << "|KG-KING|Q0-Queen|B1/B2 -bishop|R1/R2 -Rook|K1/K2 -Knight|P1,P2,P3,...,P8 -Pawns|" << std::endl;
            std::cout << std::endl;
            std::cout << "Amount should be more than 0 and less than 8 (not requried for pawns,kings,knights)" << std::endl;
            std::cout << std::endl;
            std::cout << "Directions:" << std::endl;
            std::cout << "up/left/right/down/upright/upleft/downright/downleft" << std::endl;
            std::cout << "Knight moves up right when you tell him up and moves right up when you tell him upright next clockwise is right then downright then down then downleft then left then uplift then back to up" << std::endl;
            std::cout << "special has 3 cases 'a' 'd' 'k'" << std::endl;
            std::cout << "a is default and does nothing" << std::endl;
            std::cout << "d moves the pawn twice up if he is in the right position" << std::endl;
            std::cout << "k moces the pawn to kill something in its kill range" << std::endl;
        }

        else if (piece_N == "KG")
        {
            if (Path == "up")
                (turn % 2 == 1) ? BKG.movep(up) : WKG.movep(up);
            else if (Path == "down")
                (turn % 2 == 1) ? BKG.movep(down) : WKG.movep(down);
            else if (Path == "right")
                (turn % 2 == 1) ? BKG.movep(right) : WKG.movep(right);
            else if (Path == "left")
                (turn % 2 == 1) ? BKG.movep(left) : WKG.movep(left);
            else if (Path == "upright")
                (turn % 2 == 1) ? BKG.movep(upright) : WKG.movep(upright);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BKG.movep(upleft) : WKG.movep(upleft);
            else if (Path == "downright")
                (turn % 2 == 1) ? BKG.movep(downright) : WKG.movep(downright);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BKG.movep(downleft) : WKG.movep(downleft);
        }
        else if (piece_N == "Q0")
        {
            if (Path == "up")
                (turn % 2 == 1) ? BQ0.movep(up, enteredamount) : WQ0.movep(up, enteredamount);
            else if (Path == "down")
                (turn % 2 == 1) ? BQ0.movep(down, enteredamount) : WQ0.movep(down, enteredamount);
            else if (Path == "right")
                (turn % 2 == 1) ? BQ0.movep(right, enteredamount) : WQ0.movep(right, enteredamount);
            else if (Path == "left")
                (turn % 2 == 1) ? BQ0.movep(left, enteredamount) : WQ0.movep(left, enteredamount);
            else if (Path == "upright")
                (turn % 2 == 1) ? BQ0.movep(upright, enteredamount) : WQ0.movep(upright, enteredamount);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BQ0.movep(upleft, enteredamount) : WQ0.movep(upleft, enteredamount);
            else if (Path == "downright")
                (turn % 2 == 1) ? BQ0.movep(downright, enteredamount) : WQ0.movep(downright, enteredamount);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BQ0.movep(downleft, enteredamount) : WQ0.movep(downleft, enteredamount);
        }
        else if (piece_N == "R1") {
            if (Path == "up")
                (turn % 2 == 1) ? BR1.movep(up, enteredamount) : WR1.movep(up, enteredamount);
            else if (Path == "down")
                (turn % 2 == 1) ? BR1.movep(down, enteredamount) : WR1.movep(down, enteredamount);
            else if (Path == "right")
                (turn % 2 == 1) ? BR1.movep(right, enteredamount) : WR1.movep(right, enteredamount);
            else if (Path == "left")
                (turn % 2 == 1) ? BR1.movep(left, enteredamount) : WR1.movep(left, enteredamount);
        }
        else if (piece_N == "R2") {
            if (Path == "up")
                (turn % 2 == 1) ? BR2.movep(up, enteredamount) : WR2.movep(up, enteredamount);
            else if (Path == "down")
                (turn % 2 == 1) ? BR2.movep(down, enteredamount) : WR2.movep(down, enteredamount);
            else if (Path == "right")
                (turn % 2 == 1) ? BR2.movep(right, enteredamount) : WR2.movep(right, enteredamount);
            else if (Path == "left")
                (turn % 2 == 1) ? BR2.movep(left, enteredamount) : WR2.movep(left, enteredamount);
        }
        else if (piece_N == "B1")
        {
            if (Path == "upright")
                (turn % 2 == 1) ? BB1.movep(upright, enteredamount) : WB1.movep(upright, enteredamount);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BB1.movep(upleft, enteredamount) : WB1.movep(upleft, enteredamount);
            else if (Path == "downright")
                (turn % 2 == 1) ? BB1.movep(downright, enteredamount) : WB1.movep(downright, enteredamount);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BB1.movep(downleft, enteredamount) : WB1.movep(downleft, enteredamount);
        }
        else if (piece_N == "B2")
        {
            if (Path == "upright")
                (turn % 2 == 1) ? BB2.movep(upright, enteredamount) : WB2.movep(upright, enteredamount);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BB2.movep(upleft, enteredamount) : WB2.movep(upleft, enteredamount);
            else if (Path == "downright")
                (turn % 2 == 1) ? BB2.movep(downright, enteredamount) : WB2.movep(downright, enteredamount);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BB2.movep(downleft, enteredamount) : WB2.movep(downleft, enteredamount);
        }
        else if (piece_N == "K1")
        {
            if (Path == "up")
                (turn % 2 == 1) ? BK1.movep(up) : WK1.movep(up);
            else if (Path == "down")
                (turn % 2 == 1) ? BK1.movep(down) : WK1.movep(down);
            else if (Path == "right")
                (turn % 2 == 1) ? BK1.movep(right) : WK1.movep(right);
            else if (Path == "left")
                (turn % 2 == 1) ? BK1.movep(left) : WK1.movep(left);
            else if (Path == "upright")
                (turn % 2 == 1) ? BK1.movep(upright) : WK1.movep(upright);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BK1.movep(upleft) : WK1.movep(upleft);
            else if (Path == "downright")
                (turn % 2 == 1) ? BK1.movep(downright) : WK1.movep(downright);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BK1.movep(downleft) : WK1.movep(downleft);
        }
        else if (piece_N == "K2")
        {
            if (Path == "up")
                (turn % 2 == 1) ? BK2.movep(up) : WK2.movep(up);
            else if (Path == "down")
                (turn % 2 == 1) ? BK2.movep(down) : WK2.movep(down);
            else if (Path == "right")
                (turn % 2 == 1) ? BK2.movep(right) : WK2.movep(right);
            else if (Path == "left")
                (turn % 2 == 1) ? BK2.movep(left) : WK2.movep(left);
            else if (Path == "upright")
                (turn % 2 == 1) ? BK2.movep(upright) : WK2.movep(upright);
            else if (Path == "upleft")
                (turn % 2 == 1) ? BK2.movep(upleft) : WK2.movep(upleft);
            else if (Path == "downright")
                (turn % 2 == 1) ? BK2.movep(downright) : WK2.movep(downright);
            else if (Path == "downleft")
                (turn % 2 == 1) ? BK2.movep(downleft) : WK2.movep(downleft);
        }
        else if (piece_N == "P1")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP1.movep() : WP1.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP1.Dmovep() : WP1.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP1.kill(right) : WP1.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP1.kill(left) : WP1.kill(left);
            }
        }
        else if (piece_N == "P2")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP2.movep() : WP2.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP2.Dmovep() : WP2.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP2.kill(right) : WP2.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP2.kill(left) : WP2.kill(left);
            }
        }
        else if (piece_N == "P3")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP3.movep() : WP3.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP3.Dmovep() : WP3.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP3.kill(right) : WP3.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP3.kill(left) : WP3.kill(left);
            }
        }
        else if (piece_N == "P4")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP4.movep() : WP4.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP4.Dmovep() : WP4.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP4.kill(right) : WP4.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP4.kill(left) : WP4.kill(left);
            }
        }
        else if (piece_N == "P5")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP5.movep() : WP5.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP5.Dmovep() : WP5.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP5.kill(right) : WP5.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP5.kill(left) : WP5.kill(left);
            }
        }
        else if (piece_N == "P6")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP6.movep() : WP6.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP6.Dmovep() : WP6.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP6.kill(right) : WP6.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP6.kill(left) : WP6.kill(left);
            }
        }
        else if (piece_N == "P7")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP7.movep() : WP7.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP7.Dmovep() : WP7.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP7.kill(right) : WP7.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP7.kill(left) : WP7.kill(left);
            }
        }
        else if (piece_N == "P8")
        {
            if (special == 'a')
                (turn % 2 == 1) ? BP8.movep() : WP8.movep();
            if (special == 'd')
                (turn % 2 == 1) ? BP8.Dmovep() : WP8.Dmovep();
            if (special == 'k')
            {
                if (Path == "right")
                    (turn % 2 == 1) ? BP8.kill(right) : WP8.kill(right);
                if (Path == "left")
                    (turn % 2 == 1) ? BP8.kill(left) : WP8.kill(left);
            }
        }
    }
    std::cout << "Game over or loop bugged out lol";
}


void draw()
{
    turn++;
    for (int repeater = 0; repeater < 64; repeater++)
    {
        std::cout << std::endl;
    }
    std::cout << "#################################################" << std::endl;
    std::cout << "|||||" << Positions[56] << " |" << Positions[57] << " |" << Positions[58] << " |" << Positions[59] << " |" << Positions[60] << " |" << Positions[61] << " |" << Positions[62] << " |" << Positions[63] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[48] << " |" << Positions[49] << " |" << Positions[50] << " |" << Positions[51] << " |" << Positions[52] << " |" << Positions[53] << " |" << Positions[54] << " |" << Positions[55] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[40] << " |" << Positions[41] << " |" << Positions[42] << " |" << Positions[43] << " |" << Positions[44] << " |" << Positions[45] << " |" << Positions[46] << " |" << Positions[47] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[32] << " |" << Positions[33] << " |" << Positions[34] << " |" << Positions[35] << " |" << Positions[36] << " |" << Positions[37] << " |" << Positions[38] << " |" << Positions[39] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[24] << " |" << Positions[25] << " |" << Positions[26] << " |" << Positions[27] << " |" << Positions[28] << " |" << Positions[29] << " |" << Positions[30] << " |" << Positions[31] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[16] << " |" << Positions[17] << " |" << Positions[18] << " |" << Positions[19] << " |" << Positions[20] << " |" << Positions[21] << " |" << Positions[22] << " |" << Positions[23] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[8] << " |" << Positions[9] << " |" << Positions[10] << " |" << Positions[11] << " |" << Positions[12] << " |" << Positions[13] << " |" << Positions[14] << " |" << Positions[15] << " |||||" << std::endl;
    std::cout << "|||||" << Positions[0] << " |" << Positions[1] << " |" << Positions[2] << " |" << Positions[3] << " |" << Positions[4] << " |" << Positions[5] << " |" << Positions[6] << " |" << Positions[7] << " |||||" << std::endl;
    std::cout << "#################################################" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    if (chkpic("BKG") < 64 && chkpic("WKG") < 64) {

        if (turn % 2 == 1)
            std::cout << "It is black turn" << std::endl;
        else
            std::cout << "It is white turn" << std::endl;
        std::cout << "please enter your next move in piece amount direction special " << std::endl;
    }
    else if (chkpic("BKG") == 64) {
        std::cout << "white victory" << std::endl;
        gameover = 1;
    }
    else if (chkpic("WKG") == 64) {
        std::cout << "black victory" << std::endl;
        gameover = 1;
    }
}