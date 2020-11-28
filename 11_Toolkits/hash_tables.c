#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

gboolean finder(gpointer key, gpointer value, gpointer user_data) {
    return (!g_strcmp0(key, user_data));
}


int compare_ints(gpointer a, gpointer b) {
    return GPOINTER_TO_INT(a) - GPOINTER_TO_INT(b);
}

void iterator(gpointer key, gpointer value, gpointer user_data) {
    int b = GPOINTER_TO_INT(value);
    g_array_append_val(user_data, b);
}

void iterator1(gpointer key, gpointer value, int user_data) {
    if (GPOINTER_TO_INT(value) == user_data)
         printf("%s %s\n", key, (value));
}

int main(int argc, char** argv) {
    GHashTable* hash_table = g_hash_table_new(g_str_hash, g_str_equal);
    char str[80];
    char str1[80];
    gpointer item_ptr;
    while (fgets(str1, 80, stdin)){
        strncpy(str, str1, strlen(str1)-1);
        char** mas_str;
        //printf("%s\n",str );
        mas_str = g_strsplit (str, " ", -1);
        int i = 0;
        while(mas_str[i] != NULL){
            item_ptr = g_hash_table_find(hash_table, (GHRFunc)finder, mas_str[i]);
            
            if (item_ptr == NULL){
                g_hash_table_replace(hash_table, mas_str[i], GINT_TO_POINTER(1));
                printf("ne bilo %s\n", mas_str[i]);
            } else {
                printf("bilo %s\n", mas_str[i]);
                gint item = GPOINTER_TO_INT(item_ptr);
                item += 1;
                g_hash_table_replace(hash_table, mas_str[i], GINT_TO_POINTER(item));
            }
            i++;
        }
         g_strfreev(mas_str);
    }
    printf("%d\n", g_hash_table_size(hash_table));

    GArray* a = g_array_new(FALSE, FALSE, sizeof(int));
    g_hash_table_foreach(hash_table, (GHFunc)iterator, a);
    g_array_sort(a, (GCompareFunc)compare_ints);
    printf("(%d)\n", a ->len );
    for (int j = 0; j < a -> len; j++){
        printf("%d\n",  g_array_index(a, int, j));
    }
    g_array_free(a, TRUE);
    g_hash_table_destroy(hash_table);



    

}