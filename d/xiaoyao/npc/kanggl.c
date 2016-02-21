// kanggl.c
// shilling 97.2

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
	set_name("������", ({ "kang guangling", "kang" }));
	set("long", 
		"ֻ�����߶�͹򪣬��ò��ţ�Ц���е���ɫ\n"
		"��Ϊ���ӣ����б���һ�����١�\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("inquiry", ([
        "����":(:ask_me:),
	]) );
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 200000);
	set("score", 50000);

    set_skill("blade",100);
    set_skill("ruyi-dao",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
    set_skill("beiming-shengong",100);
	set_skill("liuyang-zhang", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

	set("book_count", 1);

	create_family("��ң��", 3, "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","�ٵ�");
	setup();
	carry_object("/d/xiaoyao/obj/cloth")->wear();
//	carry_object("/d/xiaoyao/obj/blade")->wield();

}


string ask_me()
{
	object me,ob;
	ob=this_player(); 
	if (query("book_count") < 1)
		return "�������ˣ��������Ѿ����͸������ˡ�";   

	add("book_count", -1);                  
	command("say �ðɣ����ҾͰ����͸����ˡ�\n");
	message_vision(HIY"������΢Ц�Ŵӻ����ó���һ���飬���˸�$N\n\n"NOR,ob);
	me=new(__DIR__"obj/qibook");
	me->move(ob);
	return "�Ȿ���׿�ǧ��Ҫ�������ˡ�\n";
}