#include "MovePlanA.h"
#include <algorithm>

void MovePlanA::visit(Position start, std::vector<Moving> movings, StateGrid *grid)
{
    init(start, movings, grid);    
    _path.push_back(_start);
    State state = _grid->check_pos(_start);
    if (state != OK)
    {
        return;
    }
    std::vector<Moving> new_movings = _movings;
    Position cur_pos = _start;
    for (auto const moving : _movings)
    {
        Position new_pos = lookat_next(cur_pos, moving);
        state = _grid->check_pos(new_pos);
        if (state == OCCUPIED)
        {
            break;
        }
        new_movings.erase(new_movings.begin());
        cur_pos = new_pos;
        _path.push_back(cur_pos);
    }

    if (state == OCCUPIED)
    {
        std::vector<Coordinate> coors = move_around(cur_pos, new_movings); 
        if (coors.empty())
            return;
        std::cout << std::endl;
        coors.insert(coors.begin(), cur_pos.coor);

        std::vector<Moving> movings = calculate_movings(cur_pos.direction, coors);
        pure_visit(cur_pos, movings);  
    }
}


Position MovePlanA::lookat_next(Position p, Moving moving)
{
    Position pos = p;
    switch (moving)
    {
    case LEFT:
        left(pos);
        break;
    case RIGHT:
        right(pos);
        break;
    case FORWARD:
        forward(pos);
        break;
    default:
        break;
    }
    return pos;
}

void MovePlanA::left(Position &pos)
{
    pos.direction = static_cast<Direction>((pos.direction+3) % 4);
}

void MovePlanA::right(Position &pos)
{
    pos.direction = static_cast<Direction>((pos.direction+1) % 4);
}


void MovePlanA::forward(Position &pos)
{
    if (pos.direction == EAST)
        pos.coor.x += 1;
    else if (pos.direction == SOURTH)
        pos.coor.y -= 1;
    else if (pos.direction == WEST)
        pos.coor.x -= 1;
    else if (pos.direction == NORTH)
        pos.coor.y += 1;

    process_edge(pos);
}



void MovePlanA::process_edge(Position &pos)
{
    int edge_x, edge_y;
    edge_x = _grid->get_edge().x;
    edge_y = _grid->get_edge().y;

    if (pos.coor.x == (edge_x + 1))
    {
        pos.coor.x = 0;
    }
    else if (pos.coor.x == -1)
    {
        pos.coor.x = edge_x;
    }

    if (pos.coor.y == (edge_y + 1))
    {
        pos.coor.y = 0;
    }
    else if (pos.coor.y == -1)
    {
        pos.coor.y = edge_y;
    }
}


void MovePlanA::pure_visit(Position start, std::vector<Moving> moves)
{
    
    Position cur_pos = start;
    for (auto const moving : moves)
    {
        Position new_pos = lookat_next(cur_pos, moving);
        cur_pos = new_pos;
        _path.push_back(cur_pos);
    }
} 

std::vector<Coordinate>  MovePlanA::move_around(Position curr_pos, std::vector<Moving> movings)
{
    std::vector<Coordinate> whole;
    std::vector<Position> dests = lookat_possible_dests(curr_pos, movings);
    if (dests.empty())
         return whole;

    std::vector<Coordinate> coors;
    for (auto const dest : dests)
    {
        // To filter out all diff coordinates from position
        if (std::find(coors.begin(), coors.end(), dest.coor) == coors.end())
        {
            coors.push_back(dest.coor);     
        }
    }
    
    Coordinate cur = curr_pos.coor;
    for (auto const d : coors)
    {
        std::vector<Coordinate> coors_path = shortest_path(cur, d); 
        if (coors_path.empty())
        {
            continue;
        }
        else
        {
            cur = d;
            whole.insert(whole.end(), coors_path.begin(), coors_path.end());
        }
    }
    return whole; 

}

std::vector<Moving> MovePlanA::calculate_movings(Direction orig, std::vector<Coordinate> coors)
{
    std::vector<Moving> total;
    if (coors.size() <= 1)
        return total;

    Direction des; 
    std::vector<Moving> movings;
    for(std::vector<Coordinate>::iterator it = coors.begin(); it != (coors.end()-1); it++)
    {

       movings = get_neighbor_movings(*it, *(it+1), orig, des); 
       total.insert(total.end(), movings.begin(), movings.end());
       orig = des;
    }
    return total;
}


std::vector<Moving> MovePlanA::get_neighbor_movings(Coordinate s, Coordinate d, Direction src, Direction &des) 
{
    std::vector<Moving> moves;
    des = get_neighbor_direction(s, d);
    moves = turn(src, des);
    moves.push_back(FORWARD);
    return moves;
}

std::vector<Moving> MovePlanA::turn(Direction src, Direction des)
{
    std::vector<Moving> moves;

    if (des > src)
    {
        if ((des - src) == 3)
        {
            moves.push_back(LEFT); 
            return moves;
        }

        if ((des - src) <= 2)
        {
            moves.push_back(RIGHT);
        }

        if ((des - src) == 2)
        {
            moves.push_back(RIGHT);
        }
    }
    else if (src > des)
    {
        if ((src - des) == 3)
        {
            moves.push_back(RIGHT); 
            return moves;
        }

        if ((src - des) <= 2)
        {
            moves.push_back(LEFT);
        }

        if ((src - des) == 2)
        {
            moves.push_back(LEFT);
        }
 
    }
    return moves;
}

Direction MovePlanA::get_neighbor_direction(Coordinate s, Coordinate d) 
{
    //moving direction
    if ((d.y == s.y) && ((s.x + 1) == d.x)) 
        return EAST;
    if ((d.y == s.y) && ((d.x + 1) == s.x))
        return WEST;
    if ((d.x == s.x) && ((s.y + 1) == d.y))
        return NORTH;
    if ((d.x == s.x) && ((d.y + 1) == s.y))
        return SOURTH;

    int edge_x, edge_y;
    edge_x = _grid->get_edge().x;
    edge_y = _grid->get_edge().y;

    if ((s.x == edge_x) && (d.x == 0) && (d.y == s.y))
        return EAST;

    if ((s.y == 0) && (d.y == edge_y) && (d.x == s.x))
        return SOURTH;

    if ((s.x == 0) && (d.x == edge_x) && (d.y == s.y))
        return WEST;

    if ((s.y == edge_y) && (d.y == 0) && (d.x == s.x))
        return NORTH;

    std::cout<<"No direction"<<std::endl;
    return Direction(-1);
}

std::vector<Coordinate> MovePlanA::shortest_path(Coordinate cur, Coordinate dest)
{
    std::vector<Coordinate> coors;

    int i = 0;
    _grid->set_value(cur, 1);
    coors = _grid->set_neighbor(cur);
    while ((!coors.empty()) && (std::find(coors.begin(), coors.end(), dest) == coors.end()))
    {
        std::vector<Coordinate> total;
        for (auto const c : coors)
        {  
            std::vector<Coordinate> coors2 = _grid->set_neighbor(c);
            total.insert(total.end(), coors2.begin(), coors2.end());
        }
        coors = total;
        i++;
    }

    if (coors.empty())
    {
        return coors;
    }
   
    coors = list_shortest_path_coors(dest); 

    return coors;
}

std::vector<Coordinate> MovePlanA::list_shortest_path_coors(Coordinate dest)
{
    Coordinate d = dest;
    std::vector<Coordinate> coors;
    std::vector<Coordinate> v;
    int val = _grid->get_value(dest);
    while(val != 1)
    {
        coors.push_back(d);
        v = _grid->get_pre_neighbors(d);
        if (v.empty())
            break;
        d = v[0];
        val = _grid->get_value(d); 
    }
    std::reverse(coors.begin(), coors.end());
    return coors;
}

std::vector<Position>  MovePlanA::lookat_possible_dests(Position pos, std::vector<Moving> movings)
{
    std::vector<Position> possible_dest_pos;
    State state = _grid->check_pos(pos);
    if (state != OK)
    {
        return possible_dest_pos;
    }

    for (auto const moving : movings)
    {
        Position new_pos = lookat_next(pos, moving);
        state = _grid->check_pos(new_pos);
        if (state != OCCUPIED) 
        {
            possible_dest_pos.push_back(new_pos);
        }
        pos = new_pos;
    }

    return possible_dest_pos;
}
