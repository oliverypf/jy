// suck.c
//By Yzuo 97.03

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	object ob, tar;
	int sp, dp, i, j;

       if ( target == me ) target = offensive_target(me);
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭��������\n");


	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( !objectp(ob=me->query_temp("weapon")) )
		return notify_fail("��û���ñ�����\n");

	if( !objectp(tar=target->query_temp("weapon")) )
		return notify_fail("��Ķ���û���ñ�����\n");

//        if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 60 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է����������\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() +
			"û���κ�������\n");

        if( (int)target->query("neili") < 60 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�κ������ˣ�\n");

	  message_vision(
		HIR "$NͻȻ��"+ob->query("name")+"��$n��"+tar->query("name")+"ѹ��ȥ��\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "��ȫ��������ˮ����ѭ�״����Ʒ�й������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);

		target->add("neili", -1*((int)me->query_skill("huagong-dafa", 1) + target->query("jiali")) );
            if ( target->query("neili") <1 ) target->set("neili",0);
		me->add("neili", (int)me->query_skill("huagong-dafa", 1) + target->query("jiali") );

		if( target->query("combat_exp") >= me->query("combat_exp") ) {		
			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("potential", 1);
			me->add("combat_exp", 1);
		}

                me->start_busy(3);
		target->start_busy(random(3));
                me->add("neili", -7);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->start_busy(3);
		call_out("del_sucked", 4, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}
