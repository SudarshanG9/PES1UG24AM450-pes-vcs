#include "pes.h"
#include "tree.h"
#include <stdio.h>
#include <string.h>

int main() {
    system("rm -rf .pes && mkdir -p .pes/objects");
    Tree original;
    original.count = 2;
    original.entries[0].mode = 0100644;
    memset(original.entries[0].hash.hash, 0xAA, HASH_SIZE);
    strcpy(original.entries[0].name, "README.md");
    original.entries[1].mode = 0040000;
    memset(original.entries[1].hash.hash, 0xBB, HASH_SIZE);
    strcpy(original.entries[1].name, "src");

    void *data; size_t len; ObjectID id;
    tree_serialize(&original, &data, &len);
    object_write(OBJ_TREE, data, len, &id);
    return 0;
}
