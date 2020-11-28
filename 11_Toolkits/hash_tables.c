#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

gboolean finder(gpointer key, gpointer value, gpointer user_data) {
    return (!g_strcmp0(key, user_data));
}


int compare_ints(gpointer a, gpointer b) {
    int*x = (int*)a;
    int*y = (int*)b;
    return *x - *y;
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
    gint n;
    while (fgets(str1, 80, stdin)  ){
        n = 0;
        g_strlcpy(str, str1, strlen(str1)-1);
        char** mas_str;
        mas_str = g_strsplit (str, " ", -1);
        
        n = g_strv_length(mas_str);
        for (int i = 0; i < n; i++){
            item_ptr = NULL;
            item_ptr = g_hash_table_find(hash_table, (GHRFunc)finder, mas_str[i]);
            gint item1 = GPOINTER_TO_INT(item_ptr);
            gint item = 1 + item1;
            g_hash_table_replace(hash_table, mas_str[i], GINT_TO_POINTER(item));
        }
         g_strfreev(mas_str);
    }
    GArray* a = g_array_new(FALSE, FALSE, sizeof(int));
    g_hash_table_foreach(hash_table, (GHFunc)iterator, a);
    g_array_sort(a, (GCompareFunc)compare_ints);
    for (int j = 0; j < a -> len; j++){
        printf("%d\n",  g_array_index(a, int, j));
    }
    g_array_free(a, TRUE);
    g_hash_table_destroy(hash_table);
    return 0;  

}