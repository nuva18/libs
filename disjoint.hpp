#include <vector>
#include <stdio.h>

class Disjoint {
    public:
        void Init(int no_sets);
        int Find(int set);
        int Union(int s1, int s2);
        void PrintAll() const;
        void PrintSet(int set) const;
    protected:
        std::vector <int> links;
        std::vector <int> ranks;
};

/* Initialize the sets. */
void Disjoint::Init(int no_sets) {
    links.clear();
    ranks.clear();

    links.resize(no_sets, -1);
    ranks.resize(no_sets, 1);

    return;
}

/* Get the root of a set. */
int Disjoint::Find(int set) {
    int parent, child;

    if (set < 0 || set > (int) links.size()) return -1;

    /* Find the root, and reverse the direction of the links you encounter. */
    child = -1;
    while (links[set] != -1) {
        parent = links[set];
        links[set] = child;
        child = set;
        set = parent;
    }

    /* Go back and point all of the children to the root. */
    parent = set;
    set = child;
    while (set != -1) {
        child = links[set];
        links[set] = parent;
        set = child;
    }

    return parent;
}

/* Union two sets. Returns the new root, or -1 on fail. */
int Disjoint::Union(int s1, int s2) {
    int parent, child;

    if (s1 < 0 || s1 > (int) links.size() || s2 < 0 || s2 > (int) links.size()) return -1;
    if (links[s1] != -1 || links[s2] != -1) return -1;

    if (ranks[s2] > ranks[s1]) {
        parent = s2;
        child = s1;
    }
    else {
        parent = s1;
        child = s2;
    }

    links[child] = parent;
    if (ranks[parent] == ranks[child]) ranks[parent]++;

    return parent;
}

/* Prints all of the sets. */
void Disjoint::PrintAll() const {
    int i;

    printf("Sets:  ");
    for (i = 0; i < (int) links.size(); i++) printf("%3d ", i);
    printf("\n");
    printf("Links: ");
    for (i = 0; i < (int) links.size(); i++) printf("%3d ", links[i]);
    printf("\n");
    printf("Ranks: ");
    for (i = 0; i < (int) ranks.size(); i++) printf("%3d ", ranks[i]);
    printf("\n");

    return;
}

/* Prints one set. */
void Disjoint::PrintSet(int set) const {
    if (set < 0 || set > (int) links.size()) {
        printf("Set %d is invalid.\n", set);
        return;
    }

    printf("Set:  %d\n", set);
    printf("Link: %d\n", links[set]);
    printf("Rank: %d\n", ranks[set]);

    return;
}

