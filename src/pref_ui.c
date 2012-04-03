
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
	g_print("\nnumber of elements are %d",total_elements);
	store = gtk_tree_store_new(NUM_COLS,G_TYPE_STRING);
	GSList *temp = list;
	GSList *temp1 = list;
	while( temp != NULL )
	{
			DeviceData *data = (DeviceData *)temp->data;
			//g_print("\nthis is top , %u",data);
			if( g_ascii_strcasecmp(data->device_name->str,"NULL") == 0 )
			{
			g_print("\n** %s",(data->device_type->str));
				gtk_tree_store_append (store,&toplevel,NULL);
				gtk_tree_store_set (store,&toplevel,
	                    COLUMN,data->device_type->str,
	                    -1);
				
			temp1 = list;
			
			while( temp1 != NULL )
			{
				DeviceData *data1 = (DeviceData *)temp1->data;
				if( (g_ascii_strcasecmp(data->device_type->str,data1->device_type->str) == 0) && ((g_ascii_strcasecmp(data1->device_name->str,"NULL") != 0))  )
				{
					g_print("\n\t %s",data1->device_name->str);
					gtk_tree_store_append (store,&childlevel,&toplevel);
					gtk_tree_store_set (store,&childlevel,
	                    COLUMN,data1->device_name->str,
	                    -1);
				}
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}

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

void UpdateView(GtkWidget *view)
{
	GtkTreeViewColumn *col;
	GtkCellRenderer *renderer;
	GtkTreeModel *model;
	//GtkWidget *view;
	GtkTreeSelection *select;

	select = gtk_tree_view_get_selection (GTK_TREE_VIEW(view));
	g_signal_connect(select, "changed", G_CALLBACK(on_treeview_pref_devices_selection_change), "NULL");
	
	//view = gtk_tree_view_new ();
	
	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title (col,"Detected Devices");
	gtk_tree_view_append_column (GTK_TREE_VIEW(view),col);

	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_start (col,renderer,TRUE);
	gtk_tree_view_column_add_attribute (col,renderer,"text",COLUMN);

	model = CreateModel();
	gtk_tree_view_set_model(GTK_TREE_VIEW(view),model);
	g_object_unref(model);

	//return view;
}


G_MODULE_EXPORT
void on_btn_DeviceListRefresh_clicked(GtkWidget *widget, CallbackData* data)
{
	
	g_print("you have pressed refresh button\n");
	//GtkWidget * view = CreateView();
	UpdateView(data->treeview_pref_devices);
	//gtk_widget_show(view);
	//gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW (container), view);
	g_print("\n i am executed");

}


G_MODULE_EXPORT 
void on_treeview_pref_devices_selection_change(GtkWidget *widget,  CallbackData* data)
{
	GtkTreeIter iter;
  GtkTreeModel *model;
  gchar *value;


  if (gtk_tree_selection_get_selected(
      GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COLUMN, &value,  -1);
    g_print("\n selected value is : %s",value);
    g_free(value);
  }
}