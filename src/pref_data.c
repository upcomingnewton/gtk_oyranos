
#include "pref.h"
#include<glib/gprintf.h> 

GSList * populate_data()
{
	GSList * list = NULL;
	gchar *buf_type;
	gchar *buf_name;
	buf_type = (gchar *)g_malloc(80);
	buf_name = (gchar *)g_malloc(80);
	gint x = 0, y = 0;
	for( x = 0; x < 3; x++ )
	{
		g_sprintf(buf_type,"device-type %d",x);
		//g_print("\n ** %s",buf_type);
		DeviceData *data;
		data = g_new0(DeviceData,1);
		data->device_type = buf_type;
		data->device_name = "NULL";
		list = g_slist_append(list,data);
		//g_free(data);

		for( y = 0; y < 4; y++ )
		{
			g_sprintf(buf_name,"device-name %d-%d",x,y);
			//g_print("\n\t ** %s",buf_name);
			DeviceData *data;
			data = g_new0(DeviceData,1);
			data->device_type = buf_type;
			data->device_name = buf_name;
			list = g_slist_append(list,data);
			//g_free(data);	
		}
	}
	
	 g_free(buf_type);
	 g_free(buf_name);
	return list;
}