#include "recite.h"
#include "screen.h"
#include "login.h"

//词性对照表
/**  * 1: n.  * 2: v.  * 3: adj.  * 4: adv.  * 5:    */

const int phrase[10][100]={
/*unit1*/{1,1,1,1,1,1,1,1,3,1,1,1,3,1,3,3,1,2,3,2,13,1,3,1,1,4,1,1,1,3,1,3,2,2,3,3,1,2,1,2,3,3,1,1,1,3,1,1,1,1,4,1,1,3,4,1,2,1,1,4},
/*unit2*/{3,2,1,3,3,2,1,1,1,3,3,2,1,3,1,1,1,1,3,1,3,1,3,3,1,2,2,3,3,1,2,1,3,3,3,4,1,1,2,1,3,3,1,4,3,3,1,2,3,1,1,2,3,1},
/*unit3*/{1,2,1,3,2,4,3,1,3,4,3,3,1,3,3,4,1,2,3,1,3,1,3,3,4,3,2,2,1,2,2,4,1,3,1,2,3,3,3},
/*unit4*/{1,1,1,4,2,3,1,4,1,4,3,3,2,1,3,1,4,1,3,1,1,1,1,1,4},
/*unit5*/{1,1,1,3,2,2,2,1,2,1,1,1,3,1,1,2,1,4,1,1,1,3,3,2,3,2,2,1,2,4,3,1,3,4,3,4,4},
/*unit6*/{4,1,3,1,2,1,1,1,1,2,1,1,1,3,1,1,1,1,3,4,1,2,3,3,2,4,4,1,4,1,1,1,3,3,1,3,2,4,3,1,3,3,1,4,1,1,1,4,1,3,4,1,1,1,3},
/*unit7*/{3,1,3,2,1,1,3,2,3,3,1,3,3,3,1,1,1,1,3,4,3,3,3,3,2,1,3,3,3,3,1,3,1,3,1,3,3,2,2,2,3,1,2,2,3,1,2,2,3,2,1,2,2,2,2},
/*unit8*/{1,3,3,1,1,1,3,3,1,1,3,3,1,3,3,2,2,1},

/*modal*/{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0}
};
const char word[10][100][25]={
/*unit1*/{"anatomy","bureaucrat","cartoonist","clarification","clown","comedian","cross-talk","double entendre","entertaining","familiarity","gathering","humorist","humorless","idiot","irritated","laughable","laughter","misuse","mutual","prance","principal","pun","refined","riddle","riddler","selectively","setting","setup","slapstick","sparkling","string","suggestive","tease","tempt","universal","vulgar","aristocracy","assemble","clockwork","convict","cosy","dated","detection","drama","fiction","fictional","gardener","hierarchy","loose ends","miscarriage","morally","obsession","penalty","predictable","psychologically","shortage","unsettle","whereabouts","whodunit","wrongly"},
/*unit2*/{"aloof","characterize","column","complimentary","cordial","deserve","drawback","enterprise","freshness","insincere","inspiring","intrigue","investment","long-distance","mayor","memo","mentor","milestone","overdue","pad","poetic","practitioner","precise","rag-eared","recipient","savor","scribble","sentimental","spirit-lifting","stationery","thrive","typewriter","unresponsive","upbeat","vague","virtually","well-wishing","billfold","blurt","coffin","delightful","edgy","farmhouse","incessantly","mischievousness","novice","permission","proceed","ragged","remainder","serviceman","shrug","sideways","wink"},
/*unit3*/{"aspiration","assigh","bias","biased","constitute","culturally","feminine","gender","genetic","indirectly","innumerable","masculine","neatness","non-sexist","northeastern","noticeably","nursery","participation","postgraduate","preschooler","stereotyped","subordination","tremendous","unintentional","unknowingly","vital","allocate","contempt","discrimination","disregard","disrupt","dramatically","essay","hopeful","lecturer","pervade","rightful","sloppy","unladylike"},
/*unit4*/{"educator","motivation","multiplication","practically","scorn","workable","agenda","awkwardly","dexterity","expectantly","exploratory","incomplete","intervene","intervention","intrusive","manual","mere","passerby","rectangular","reorient","shirttail","slot","stroller","vicinity","vigorously"},
/*unit5*/{"athlete","cereal","championship","confining","dunk","endorsement","half-time","honesty","outweigh","pastureland","pedestal","publicity","scary","sneaker","tightrope","worship","arena","artificially","athletics","attorney","champion","conceited","courageous","deform","disadvantaged","discard","eligibility","fame","flatter","fundamentally","gloriously","heavyweight","indomitable","invariably","legitimate","legitimately","misguided","needless","overprotect","paradox","perpetually","pipe","fitter","privilege","privileged","rape","reasoning","rightfully","selflessness","sexual","shield","statewide","talented","thankfully","thrilling","unheard-of","unremarkable"},
/*unit6*/{"accordingly","armored","definitive","denominator","explosure","fraction","hypochondria","hypochondriac","inconvenience","inflate","miner","neurotic","numerator","partial","physician","probability","ratio","riskiness","risky","roughly","symptom","versus","catastrophic","costly","discount","disproportionately","enormously","funding","hence","immediacy","incidence","incubation","indifferent","insignificant","killer","lesser","loom","nonetheless","notable","payable","permanent","piper","preoccupation","principally","proportion","radiation","reassessment","repeatedly","seriousness","short-sighted","specifically","stroke","terror","time lag","understandable"},
/*unit7*/{"adequate","commencement","crucial","erase","faculty","fantasy","forgiving","formulate","garrulous","mediocre","midterm","painless","parlous","preparatory","school","presentation","pretense","quitter","slipshod","supposedly","tolerant","triple","unchallenging","unimaginative","unlearn","administrator","arcane","bizarre","chilling","contented","curse","demented","desperation","downhill","executive","exhilarating","frigid","glaze","glide","kneel","leisurely","moan","mutter","obscure","pathetic","precursor","realization","regurgitate","rotten","scrunch","sidewalk","soothe","stagger","stomp","weep"},
/*unit8*/{"addict","antique","biochemical","brink","chronobiology","cult","external","hispanic","humankind","inborn","internal","mob","outgoing","perceptual","reshape","resynchronise","stove","synchronise","synchroniser","thereby","timepiece","tyranny","unclock","unison","wristwatch","absurd","agriculturist","consciously","context","counterpart","distortion","embassy","explicit","heel","interval","relay","reluctantly","stir","unreasonable","urgency","utmost"},
/*unit9*/{"adaptable","assimilate","atomic","batch","blacksmith","bloom","contradict","convert","disastrous","emotionally","ethic","evolution","experimentation","geomentrically","icebox","innovation","objectivity","obsolete","prosperity","revolutionize","scholar","segment","activate","alphabetical","centimeter","correlation","delicately","evaluator","experimental","holograph","intimate","manipulation","measurement","molecular","programmer","psychiatric","requirement","resonance","resonate","tab","temperamental","valve"},
/*unit10*/{"bald","bard","breathlessly","brogue","bug","clout","commentary","flunk","fumble","gravely","hardware","humiliation","idiom","illustrious","indignantly","instructor","memento","mercy","mumble","mustache","overhear","pasteboard","physicist","posterity","primly","queer","script","sidle","simpleton","straggly","surmise","telescope","temporal","transference","untouched","vest","wholesale","wring","yell","absence","accusation","affidavit","agony","ale","anguish","apprehensively","asylum","baseless","behold","bitterly","blackmail","bribery","brutal","cabin","candidacy","clamor","climax","corruptionist","deceased","delirium trements","democratic","disgraceful","disheartening","drunken","dub","falsehood","filthy","gazette","gubernatorial","heartless","incite","infamous","inmate","intent","liar","liquor","listlessly","lunatic","nominate","obstruct","outraged","perjury","persecution","plantain","rattlesnake","republican","robbery","shameful","shameless","slander","snatcher","suspiciously","undercurrent","vengeance","vile","vote","withdrawal"}
};
const char letter[10][100][80]={
/*unit1*/{"#构造，结构，解剖学","官僚主义者","漫画家","澄清，解释","小丑","滑稽演员，喜剧演员","相声","双关语(d开头)","有趣的，令人愉快的","熟悉，精通","聚会","有幽默感的人","缺乏幽默感的","笨蛋蠢材","恼火的，不耐烦的","可笑的，荒唐的","笑声","滥用，误用","相互的，共同的，共有的","神气活现的走","校长,最重要的","双关语(p开头)","有礼貌的，有品位的","谜语，奥秘","出谜语的人","有选择地","背景","机制，结构","滑稽表演，打闹剧","闪亮的，闪光的","一连串，线，弦","让人产生邪念的，挑逗的","戏弄，取笑","怂恿，引诱去做","普遍的，通用的","庸俗的，粗俗的","贵族","集合，聚集，组合装配","发条装置","宣判，有罪，囚犯","舒适的，亲切的","过时的，老式的","发觉，察觉","戏剧，电视剧","小说","小说的，虚构的","园丁","等级制度","未完成部分","审判不公，误判","道德上，道义上","着魔，迷恋，困扰人的想法","刑罚，处罚","可预料的","心理地","短缺，缺乏","使不安，扰乱","行踪，去向","侦探小说（电影）","不正确地，错误地"},
/*unit2*/{"冷淡的，超然离群的","描绘...的特征","专栏","赞美的","诚挚而友好的","应得，应受","不利条件，缺点，弊端","企业公司","新意， 勃勃生机","不真诚的","激励人心的，启发灵感的","激起...的好奇心","投资","远距离的，长途的","市长，镇长","备忘录","导师，指导者","重大事件，里程碑","早该发生的，延误的","便筏本，拍纸薄","富有诗意的","从事者，实践者","精确的","折角的，破旧的","接受者","品味，体验，品尝","潦草地书写，乱画","多愁善感的，多情的","鼓舞人心的","文具，信纸","繁荣，兴旺，茁壮成长","打字机","无反应的，冷淡的","乐观的，快乐的","含糊的，不明确的","差不多，实际上","良好祝愿","皮夹子","脱口而出","棺材","令人愉快的，漂亮的","易怒的，不安的","农舍","不停地","淘气，调皮","新手的","允许","超某个方向前进，移动","破旧的","剩下的人，东西，时间","军人","耸肩（表示怀疑冷漠）","向一边的，横着的","眨眼"},
/*unit3*/{"强烈愿望，志向","分配，分派","偏见成见","有偏见的","被视为，组成，设立","文化上，人文地","女性的，妇女的","性别","基因的"," 间接地","无数的，数不清的","男性的，男子气概的","整洁","非性别歧视的","来自东北部的","显著地，明显地","托儿所","参与，参加","博士后的","学龄前儿童","老一套的，模式化的","处于次要地位","巨大的，极快的，强有力的","不是故意的，无心的","不知道地，没意识到地","极其重要的，必不可少的","分配，配给","轻视，轻蔑","歧视","忽视，不顾","扰乱，使混乱","显著地","短文，小品，散文","有希望的","讲师","遍布，弥漫","合法的，公正的","马虎的，凌乱的","缺乏淑女风度的"},
/*unit4*/{"教育家","动力，积极性","乘法运算，乘法表","几乎，简直，实际上","轻蔑，鄙视","可行的，切合实际的","意图，计划，议事日程","笨拙地","轻巧","期望地","探索的，考察的","不完整的","干涉，干预","介入，干涉，干预","干涉的，不受欢迎的","手工的，体力的；手册，指南","仅仅，只不过","过路人","长方形的","重新定...的方位，方向","衬衣下摆","窄缝，宅槽","婴儿车","近处，邻近地区","强有力地"},
/*unit5*/{"运动员","谷类早餐，谷类作物","冠军地位，冠军称号","局限的，限制的","灌篮，扣篮","赞许，赞同，支持","中场休息","诚实","在重量，价值，或重要性上超过","牧场","（雕像，柱子等）底座","（报纸，电视等）对某人某事的关注","可怕的，恐怖的","胶底运动鞋","棚索，钢丝","崇拜，崇敬，敬奉，信奉","领域，活动舞台","人为地，人工地","体育运动","律师","冠军，捍卫者，拥护者","自负的","有勇气的，勇敢的","使成畸形，使变形","弱势的，地位低下的","丢弃，抛弃，清除","有资格","名誉，名声，声望","谄媚，奉承","根本地，基本地","光荣地，辉煌地，壮丽地","重量级拳击手，巨头，重量级人物","不屈服的，不可战胜的","不可避免地，必然发生地","总是，始终如一地","公正合理的，合法的","合理地，正当地","想法或行动错误的","不必要的，不需要的","过分保护","自行矛盾（的情况）","无休止地，频繁（以至于令人厌恶）地","管道工","特权，优惠，荣幸","（因富有，有权势等）有特权的","强奸","推论，推理","合法地，正当地","性的，与性有关的","保护；防护罩","影响全州的，全州范围的","有天赋的，有才能的","幸运地， 万幸地，感激地","引人入胜的，令人激动的","前所未闻的","平凡的，不引人注意的"},
/*unit6*/{"相应地，因而，从此","装甲车","确定的,决定性的,最可靠的,最权威的","分母","暴露，揭露，揭发","分数，小数，一点，少量","疑病症","疑病症患者","麻烦，不便","使充满气体，使膨胀，吹捧","矿工","神经病患者","分子","部分的，偏袒的，不公平的","（内科）医生","可能性，概率","比率，比例","风险性","冒险的，非常危险的","大概，大约","症状，征兆","与什么相对（相比），...对...","灾难性的","过于昂贵的，代价高的","不全相信，不重视；打折","不成比例地","极大程度上，极其地","专款，拨款","因此，从此时起","即时性，紧迫性","发生率，发病率","疾病的潜伏期","冷漠的，不关心的，一般的","不重要的，无足轻重的","杀手","较小的，次要的","赫然出现","尽管如此","值得注意的","应支付的，可支付的","永恒的","吹笛人","全神贯注","主要地","比例，部分，份儿","辐射","重新评估","一再，反复地","严重性","目光短浅的，近视的","明确地，确切地","中风，脑卒中","恐惧","时间差，时间间隔","可以理解的，合情理的"},
/*unit7*/{"适当的，足够的，差强人意的","毕业典礼，开始","至关重要的","擦掉，抹去","全体教员，系，科，学院，能力，天赋","空想，想象，幻想","宽容的","确切地表达，构想，制定","喋喋不休的","平庸的","期中考试","容易的，省事的","恶劣的，危险的","准备阶段的","私立学校，预备学校","陈述，说明，介绍，提供，授予","假装，伪装","轻易放弃的人，半途而废的人","不认证的，马虎的","据认为","宽容的，容忍的","三部分的，三倍的；三人间","轻松的，毫无挑战的","毫无想象力的","抛掉，设法忘记","管理者","神秘的，晦涩难懂的","古怪的","使人害怕的","满足的，满意的","咒骂，臭骂;骂人的话，祸根","奇怪的，愚蠢的，疯狂的","绝望","下坡的","主管，经理","令人兴奋的，令人振奋的","寒冷的，严寒的","眼睛变呆滞","滑动，滑行","跪","悠闲的，从容的，慢悠悠的；悠闲的","抱怨,呻吟,呜咽声;呻吟,抱怨","咕哝，嘀咕，小声说","晦涩难懂，鲜为人知；使难理解","令人同情的，无用的","前身，先驱，先兆","认识到，意识到，实现","（不加思考地）重复","令人不快的，腐烂的，很差的","挤压，皱紧(身体部分),压,碾","人行道","抚慰，减轻","蹒跚，使吃惊，使（时间）错开；蹒跚","跺脚，重踩"," 哭泣，（伤口）渗出液体"},
/*unit8*/{"对...着迷的人","古老的；古董","生物化学的","边缘，关头","时间生物学","邪教，时尚观念，态度","外在的，外部的，外用的","与葡萄牙语有关的","人类","湿度，湿热","与生俱来的","内部的，国内的，体内的","暴民，乌合之众；围住，围攻","外出的，离开的，性格外向的","感知的，感觉的","给...以新形式","重新同步","炉子","（使）同步","同步","借此，从而，因此","表，钟","控制，支配，暴政，专制政府","使不受时间约束","一致的或协调的行动","手表","荒谬的，荒唐的","农学家，农业技师","有意识地","环境，背景，上下文","职务相当的人，功能相当的物","曲解，歪曲，变形，失真","大使馆全体官员，大使馆","明确的，清晰的","（鞋，袜，脚的）后跟","间歇，间隔，中场休息","传达，传递，转播","不情愿地，勉强地","激发，激起","不合理的，不理智的","紧迫，迫切","极度的，最大的；极限，最大可能"},
/*unit9*/{"适应性强的，能适应的","吸收，理解，掌握，融入，加入，被同化","原子能的，原子的","一批，一群，一组","铁匠","开花，绽放；花","同...矛盾，反抗，否认，抗辩","（使）转化（使）改变信仰","灾难性的，很糟的，失败的","情感上地，情绪上地","道德标准，道德规范","演变，进化论","实验，试验","按几何级数地","冰箱，电冰箱","新观念，新发明，新方法，革新","客观性","被淘汰的，过时的","繁荣，成功","使彻底变革","学者，奖学金获得者","部分，片，断，瓣","启动，使活动","按字母表顺序的","厘米","相互关系，关联","谨慎地","评估员，评价者","实验性的","全息照片","至交；隐私的，个人的；暗示","操纵，控制","长度，高度，衡量，大小","分子的","计算机程序员","精神病学的，精神病治疗的","要求，条件，必需品","共鸣","（使）产生情感共鸣","小纸条，小布条","气质的，性情的，性格的，喜怒无常的","阀，活门，瓣膜"},
/*unit10*/{"秃头的","诗人","气喘吁吁地","土腔","突出,张大,烦扰,纠缠；虫子,窃听器","一块布","评论，注释，实况报道，现场解说","（使）不及格","笨手笨脚地摸索","严肃地，认真地","五金器具，硬件","羞耻，丢脸","习语，成语","卓越的，著名的","愤怒地，愤慨地"," 大学讲师，教练，教员","小纪念品","慈悲，宽容","含糊地说，咕哝","八字须","无意中听到","硬纸板","物理学家"," 后代","一本正经地，古板地","古怪的，难以解释的","笔记，手写体","悄悄走进，鬼鬼祟祟地走向某人","傻瓜，呆子","凌乱的，蔓延的","推测，猜测","望远镜","关于时间的，短暂的，受时间限制的","转移，传输，调动","没有被碰过的，未吃过的","马甲，背心；授予，赋予","批发，批发的","拧干，搓手，尽力索取，强行取得","叫喊，大叫大嚷","缺席，不存在","质控，控告","宣誓书，书面证词","痛苦，苦难","高酒精度啤酒，麦芽酒","（身体上的）剧痛，（精神上的）痛苦","担忧的",
        "精神病院，避难所，庇护所","无根据的","看到，见到","痛苦地，愤怒地","敲诈，勒索","行贿","野兽般的，残忍的，不顾他人感情的","小木屋，船舱，机舱","候选资格，候补地位","要求，吵闹声，嘈杂声","高潮；（使）达到高潮","（政治中）私营舞弊者","死者，已故之人","震颤性谵妄","美国民主党的，民主的","丢脸的，可耻的","令人沮丧的，令人灰心的","醉的","给...起绰号，配音","谎言，说谎，虚假性"," 猥琐的，肮脏的，污秽的","报纸","州长的","无情的，冷酷的","激起，煽动","声名狼藉的","囚犯，精神病院的病人","目的，意图；渴望的，专注的","说谎者","烈性酒","倦怠地，无精打采地","精神病患者，疯子","提名，推荐，任命，指定","挡住，遮住，阻塞","狂怒的","作伪证者，发假誓者","迫害，虐待","大蕉","响尾蛇","共和党的，共和国的；共和党人","抢劫（案），盗窃（案）","可耻的","无耻的","诽谤","绑架者，抢夺者","怀疑地","潜伏的情绪","报仇，复仇","卑鄙的，可耻的，恶劣的","投票，选举","收回，撤销，提款（额）"}
};
//mark：已过  err：错误次数  bingo：正确次数
short mark[10][100],err[10][100],bingo[10][100];
short If_file_exist;
//主数据结构
struct menu menu;
//颜色表
void test_color(){
    int i;
    for(i=0;i<256;i++){
        color(i);
        if(i%16 == 0 &&i)
            printf("\n");
        printf("%3d  ",i);
    }
    getchar();
}
//储存数据
void Put_log(){
    if(If_file_exist){
        FILE *flog = NULL;
        flog = fopen("log.json","w+");
        short unit;
        fprintf(flog,"//别看了，会眼瞎的\n");
        fprintf(flog,"{");
        for(unit = 1 ; unit <= 10 ; unit++){
            short num = Get_Word_num(unit);
            short i;
            fprintf(flog,"\n\t\"unit%d\":[",unit);
            for(i = 0 ; i < num ; i++){
                if(i)
                    fprintf(flog,",");
                fprintf(flog,"\n\t\t{\"m%02d\": %d ,\"e%02d\": %d ,\"r%02d\": %d }",i+1,mark[unit-1][i],i+1,err[unit-1][i],i+1,bingo[unit-1][i]);
            }
            fprintf(flog," \n\t],");
        }
        //依次是：名字、错误重写、颜色（中文、输入、错误、词性）
        fprintf(flog,"\n\t\"name\":\" %s \",",menu.name);
        fprintf(flog,"\n\t\"repeat\": %d ,",reciting.repeat);
        fprintf(flog,"\n\t\"color_ch\": %d ,",Color_ch);
        fprintf(flog,"\n\t\"color_input\": %d ,",Color_input);
        fprintf(flog,"\n\t\"color_wrong\": %d ,",Color_wrong);
        fprintf(flog,"\n\t\"color_phr\": %d ,",Color_phr);
        fprintf(flog,"\n}");
        fclose(flog);
    }
}
//读取数据
short Read_log(){
    FILE *flog = NULL;
    flog = fopen("log.json","r");
    if(flog){
        short unit;
        char ban[30];   //无用的json结构
        fscanf(flog,"%s",ban);//别看了，会眼瞎的
        fscanf(flog,"%s",ban);
        for(unit = 1 ; unit <= 10 ; unit ++){
            fscanf(flog,"%s",ban);
            short num = Get_Word_num(unit);
            short i , useless;
            for(i = 0 ; i < num ; i++){
                fscanf(flog,"%s",ban);
                fscanf(flog,"%d",&mark[unit-1][i]);
                fscanf(flog,"%s",ban);
                fscanf(flog,"%d",&err[unit-1][i]);
                fscanf(flog,"%s",ban);
                fscanf(flog,"%d",&bingo[unit-1][i]);
                fscanf(flog,"%s",ban);
            }
            fscanf(flog,"%s",ban);
        }
        fscanf(flog,"%s%s%s",ban,menu.name,ban);
        fscanf(flog,"%s%d%s",ban,&reciting.repeat,ban);
        fscanf(flog,"%s%d%s",ban,&Color_ch,ban);
        fscanf(flog,"%s%d%s",ban,&Color_input,ban);
        fscanf(flog,"%s%d%s",ban,&Color_wrong,ban);
        fscanf(flog,"%s%d%s",ban,&Color_phr,ban);
        fscanf(flog,"%s",ban);
        fclose(flog);
        return 1;
    }else
        return 0 ;
}
//初始化
void Ini(){
    int i , j;
    for(i = 0 ; i < 10 ; i++)
        for(j = 0 ; j < 100 ; j++)
            mark[i][j] = err[i][j] = bingo[i][j] = 0 ;
    reciting.repeat = 1;
    If_file_exist = 0;
    Color_ini();
}
//新功能测试区
void test(){

    printf("%d",Color_twhite);

    getch();
}
//切换页面
void Change_site(){
    switch( menu.mode ){
    case 1:
        menu.unit = 1;
        Print_Select_unit(8,30);
        Select_unit();
        if(menu.unit <= 10){
            Select_order();
            Recite();
        }
        break;
    case 2:
        menu.unit = 1;
        Print_Select_unit(8,30);
        Select_unit();
        if(menu.unit <= 10)
            Show_word();
        break;
    case 3:
        Login();
        break;
    case 4:
        Setting();
        break;
    case 5:
        Reset();
        break;
    //case 6:
        //Game();
       //break;
    default:
        Goto(40,10);
        color(Color_bg_home+4);
        printf("啥也没有，请回吧");
        getch();
        break;
    }
}
//主程序
int main(){
    //启动时初始化
    Ini();
    //读入可能存在的数据
    If_file_exist = Read_log();
    //test();
    while(1){
        //主页-->screen.c
        home();
        //切换页面
        Change_site();
    }
    return 0;
}





