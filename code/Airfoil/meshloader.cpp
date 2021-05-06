
#include"meshloader.h"
#include<iostream>

int MeshLoader::load(){
    printf("reading in grid \n");

    FILE* fp;
    if ((fp = fopen("./new_grid.dat", "r")) == NULL)
    { //open the file
        printf("can't open file new_grid.dat\n");
        return 0;
    }

    int nnode, ncell, nedge, nbedge;

    if (fscanf(fp, "%d %d %d %d \n", &nnode, &ncell, &nedge, &nbedge) != 4)//get the total num
    {
        printf("error reading from new_grid.dat\n");
        return 0;
    }

    node_num = nnode;
    cell_num = ncell;
    edge_num = nedge;
    bedge_num = nbedge;

    //set variables for graph coloring
    int* cell2edge = (int*)malloc(4 * ncell * sizeof(int));
    for (int i = 0; i < 4 * ncell; ++i)
    {
        cell2edge[i] = -1;
    }

    for (int n = 0; n < nnode; n++)//read the nodes
    {
        double x_tmp, y_tmp;
        if (fscanf(fp, "%lf %lf \n", &x_tmp, &y_tmp) != 2)
        {
            printf("error reading from new_grid.dat\n");
            return 0;
        }
        x_vals.push_back(x_tmp);
        x_vals.push_back(y_tmp);
    }

    for (int n = 0; n < ncell; n++)//read the cells
    {
        int n1, n2, n3, n4;
        if (fscanf(fp, "%d %d %d %d \n", &n1, &n2,&n3, &n4) != 4)
        {
            printf("error reading from new_grid.dat\n");
            return 0;
        }
        cell_vals.push_back(n1);
        cell_vals.push_back(n2);
        cell_vals.push_back(n3);
        cell_vals.push_back(n4);
    }

    for (int n = 0; n < nedge; n++)//read the edeges
    {
        int e1, e2, ec1, ec2;
        if (fscanf(fp, "%d %d %d %d \n", &e1, &e2,
            &ec1, &ec2) != 4)//just read
        {
            printf("error reading from new_grid.dat\n");
            return 0;
        }
        edge_vals.push_back(e1);
        edge_vals.push_back(e2);
        ecell_vals.push_back(ec1);
        ecell_vals.push_back(ec2);
        //deal with the two edge cells of the edge:
        /*
        for (int i = 0; i < 4; ++i)//set the remained edge of this cell as this edge
        {

            if (cell2edge[ecell_vals.at( 2 * n ) + i] == -1)
            {
                cell2edge[ecell_vals.at( 2 * n )+ i] = n;
                break;
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if (cell2edge[ecell_vals.at(2 * n + 1) + i] == -1)
            {
                cell2edge[ecell_vals.at( 2 * n + 1) + i] = n;
                break;
            }
        }
        */
    }

    for (int n = 0; n < nbedge; n++)//read the edge and bound
    {
        int _bedge1, _bedge2, _becell, _bound;
        
        if (fscanf(fp, "%d %d %d %d \n", &_bedge1, &_bedge2,
            &_becell, &_bound) != 4)
        {
            printf("error reading from new_grid.dat\n");
            return 0;
        }
        bedge_vals.push_back(_bedge1);
        bedge_vals.push_back(_bedge2); 
        becell_vals.push_back(_becell);
        bound_vals.push_back(_bound);
        
    }
    fclose(fp);
    return 1;//successful flag
}

vector<Node> MeshLoader::getNodes() {
    vector<Node> nodes;
    for (int i = 0; i < node_num; i++) {
        nodes.push_back(Node(x_vals.at(i * 2), x_vals.at(i * 2 + 1)));
    }
    return nodes;
}

vector<Edge> MeshLoader::getEdges() {
    vector<Edge> edges;
    vector<Node> nodes = getNodes();
    vector<Cell> cells = getCells();

    for (int i = 0; i < edge_num; i++) {
        edges.push_back(
            Edge(nodes.at(edge_vals.at(i * 2)),
                nodes.at(edge_vals.at(i * 2 + 1)),
                cells.at(ecell_vals.at(i * 2 )),
                cells.at(ecell_vals.at(i * 2 + 1))
            )
        );
    }
    return edges;
}

vector<Bedge> MeshLoader::getBoundEdges() {
    vector<Bedge> bedges;
    vector<Node> nodes = getNodes();
    vector<Cell> cells = getCells();
   
    for (int i = 0; i < bedge_num; i++) {
        bedges.push_back(
            Bedge(
                nodes.at(bedge_vals.at(2 * i)),
                nodes.at(bedge_vals.at(2 * i + 1)),
                cells.at(becell_vals.at(i)),
                cells.at(bound_vals.at(i))
            )
        );
    }
    
    return bedges;
}

vector<Cell> MeshLoader::getCells() {
    vector<Cell> cells;
    vector<Node> nodes = getNodes();
    for (int i = 0; i < cell_num; i++) {
        cells.push_back(
            Cell(
                nodes.at(cell_vals.at(i * 4)),
                nodes.at(cell_vals.at(i * 4 + 1)), 
                nodes.at(cell_vals.at(i * 4 + 2)),
                nodes.at(cell_vals.at(i * 4 + 3))
            )
        );
    }
    return cells;
}
