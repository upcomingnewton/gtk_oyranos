
#ifndef HAVE_OY_CONFIG_H
#define HAVE_OY_CONFIG_H
#include "oy_config.h"
#endif

typedef struct _devices_data DeviceData; 
struct _devices_data
{
	//gchararray device_name[40];
	//gchararray device_type[40];
	GString* device_name;
	GString* device_type;
};

GSList * populate_data();
GtkWidget * CreateView();
G_MODULE_EXPORT void on_btn_DeviceListRefresh_clicked(GtkWidget *widget,  CallbackData* data);
void UpdateView(GtkWidget *view);
G_MODULE_EXPORT void on_treeview_pref_devices_selection_change(GtkWidget *widget,  CallbackData* data);