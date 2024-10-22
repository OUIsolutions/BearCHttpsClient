
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end


LuaCEmbedResponse *  internal_lua_cembed_generate_code(LuaCEmbedTable *self,LuaCEmbed *args,bool watch){

    char *src = lua.args.get_str(args,0);
        char *imports = lua.args.get_str(args,1);
        char *shortcut  = lua.args.get_str(args,2);
        LuaCEmbedTable *table_tags = lua.args.get_table(args,3);
        bool generate_main = false;
        char *main_name =NULL;
        char *main_path = NULL;
        if (lua.args.size(args) >= 5){
            generate_main = true;
            main_name = lua.args.get_str(args,4);
        }
        if(lua.args.size(args) >= 6){
            main_path = lua.args.get_str(args,5);
        }
        if(lua.has_errors(args)){
            char *msg  = lua.get_error_message(args);
            return lua.response.send_error(msg);
        }

        DtwStringArray *tags = newDtwStringArray();
        for (int i =0;i < lua.tables.get_size(table_tags);i++){
            char *current = lua.tables.get_string_by_index(table_tags,i);
            if(lua.has_errors(args)){
                char *msg  = lua.get_error_message(args);
                dtw.string_array.free(tags);
                return lua.response.send_error(msg);
            }
            dtw.string_array.append(tags,current);
        }
        if(!watch){
            generate_code(src,imports,shortcut,tags,true,"main.c",NULL);
        }
        if(watch){
            generate_code_in_watch_mode(src,imports,shortcut,tags,true,"main.c",NULL,1);
        }
        dtw.string_array.free(tags);

        return NULL;
}
LuaCEmbedResponse * lua_cembed_silver_chaingenerate_code_once(LuaCEmbedTable *self,LuaCEmbed *args){
    return  internal_lua_cembed_generate_code(self,args,false);
}

LuaCEmbedResponse * lua_cembed_silver_chaingenerate_code_watch(LuaCEmbedTable *self,LuaCEmbed *args){
    return internal_lua_cembed_generate_code(self,args,true);
}
