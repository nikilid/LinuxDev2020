#include <glib.h>
#include <stdio.h>
#include <string.h>

gboolean finder(gpointer key, gpointer value, gpointer user_data) {
    return !g_ascii_strcasecmp(key, user_data);
}


gint compare_ints(gconstpointer  c, gconstpointer  b, gpointer hash_table) {
    gpointer x = g_hash_table_find(hash_table, (GHRFunc)finder, (gpointer)c);
    gpointer y = g_hash_table_find(hash_table, (GHRFunc)finder, (gpointer)b);
    return  GPOINTER_TO_INT(x)- GPOINTER_TO_INT(y);
}


int main(int argc, char** argv) {
    GHashTable* hash_table = g_hash_table_new(g_str_hash, g_str_equal);
    char str[80];
    char str1[80];
    gpointer item_ptr;
    gint n;
    GList* l = NULL;
    while (fgets(str, 80, stdin)){
        n = 0;
        str[strlen(str)-1] = '\0';
        char** mas_str;
        mas_str = g_strsplit (str, " ", -1);
        
        n = g_strv_length(mas_str);
        for (int i = 0; i < n; i++){
            item_ptr = NULL;
            gchar* tmp = g_strdup(mas_str[i]);
            item_ptr = g_hash_table_find(hash_table, (GHRFunc)finder,tmp);
            gint item1 = GPOINTER_TO_INT(item_ptr);
            gint item = 1 + item1;
            g_hash_table_replace(hash_table, tmp, GINT_TO_POINTER(item));

            if (item == 1){
               l = g_list_append(l, tmp);
            }
        }
         g_strfreev(mas_str);
    }
    l = g_list_sort_with_data(l, (GCompareDataFunc)compare_ints, hash_table);
    while (g_list_first(l) != NULL){
        item_ptr = g_hash_table_find(hash_table,(GHRFunc)finder, GINT_TO_POINTER(g_list_first(l)->data));
        printf("%s %d\n",  g_list_first(l)->data, GPOINTER_TO_INT(item_ptr));
        l = g_list_remove(l, g_list_first(l)->data);
    }
    g_list_free(l);
    g_hash_table_destroy(hash_table);
    return 0;  
}