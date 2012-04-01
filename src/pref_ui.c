
#include "pref.h"

enum
{
	COLUMN,
	NUM_COLS
};

GtkTreeModel * CreateModel()
{
		GtkTreeStore *store;
		GtkTreeIter toplevel,childlevel;
		GSList *list = NULL;
	list = populate_data();
	if( list == NULL )
	{
		g_print("\n Error :  could not populate devices");
		//exit(1);
	}
	gint total_elements = 0;
	total_elements = g_slist_length(list);
	store = gtk_tree_store_new(NUM_COLS,G_TYPE_STRING);
	GSList *temp = list;
	while( temp != NULL )
	{
			DeviceData *data = (DeviceData *)temp->data;
			g_print("\nthis is top , %u",data);
			if( g_ascii_strcasecmp() == 0 )
		{
			g_printf("")
		}
		temp = temp->next;
	}
	

	gtk_tree_store_append (store,&toplevel,NULL);
	gtk_tree_store_set (store,&toplevel,
	                    COLUMN,"device type 1",
	                    -1);
	
	gtk_tree_store_append (store,&childlevel,&toplevel);
	gtk_tree_store_set (store,&childlevel,
	                    COLUMN,"device 1",
	                    -1);

	gtk_tree_store_append (store,&childlevel,&toplevel);
	gtk_tree_store_set (store,&childlevel,
	                    COLUMN,"device 2",
	                    -1);

	gtk_tree_store_append (store,&childlevel,&toplevel);
	gtk_tree_store_set (store,&childlevel,
	                    COLUMN,"device 3",
	                    -1);
	g_slist_free(list);
	return GTK_TREE_MODEL( store);
	
}

GtkWidget * CreateView()
{
	GtkTreeViewColumn *col;
	GtkCellRenderer *renderer;
	GtkTreeModel *model;
	GtkWidget *view;

	view = gtk_tree_view_new ();
	
	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title (col,"Detected Devices");
	gtk_tree_view_append_column (GTK_TREE_VIEW(view),col);

	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start (col,renderer,TRUE);
	gtk_tree_view_column_add_attribute (col,renderer,"text",COLUMN);

	model = CreateModel();
	gtk_tree_view_set_model(GTK_TREE_VIEW(view),model);
	g_object_unref(model);

	return view;
}

