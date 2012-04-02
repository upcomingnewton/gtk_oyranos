#include<gtk/gtk.h>

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