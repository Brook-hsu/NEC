#include "recite.h"
#include "screen.h"
#include "login.h"

//���Զ��ձ�
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
/*unit1*/{"#���죬�ṹ������ѧ","����������","������","���壬����","С��","������Ա��ϲ����Ա","����","˫����(d��ͷ)","��Ȥ�ģ���������","��Ϥ����ͨ","�ۻ�","����Ĭ�е���","ȱ����Ĭ�е�","��������","�ջ�ģ����ͷ���","��Ц�ģ����Ƶ�","Ц��","���ã�����","�໥�ģ���ͬ�ģ����е�","�������ֵ���","У��,����Ҫ��","˫����(p��ͷ)","����ò�ģ���Ʒλ��","�������","���������","��ѡ���","����","���ƣ��ṹ","�������ݣ����־�","�����ģ������","һ�������ߣ���","���˲���а��ģ�������","ϷŪ��ȡЦ","����������ȥ��","�ձ�ģ�ͨ�õ�","ӹ�׵ģ����׵�","����","���ϣ��ۼ������װ��","����װ��","���У��������","���ʵģ����е�","��ʱ�ģ���ʽ��","���������","Ϸ�磬���Ӿ�","С˵","С˵�ģ��鹹��","԰��","�ȼ��ƶ�","δ��ɲ���","���в���������","�����ϣ�������","��ħ�������������˵��뷨","�̷�������","��Ԥ�ϵ�","�����","��ȱ��ȱ��","ʹ����������","���٣�ȥ��","��̽С˵����Ӱ��","����ȷ�أ������"},
/*unit2*/{"�䵭�ģ���Ȼ��Ⱥ��","���...������","ר��","������","��ֿ���Ѻõ�","Ӧ�ã�Ӧ��","����������ȱ�㣬�׶�","��ҵ��˾","���⣬ ��������","����ϵ�","�������ĵģ�������е�","����...�ĺ�����","Ͷ��","Զ����ģ���;��","�г�����","����¼","��ʦ��ָ����","�ش��¼�����̱�","��÷����ģ������","�㷤������ֽ��","����ʫ���","�����ߣ�ʵ����","��ȷ��","�۽ǵģ��ƾɵ�","������","Ʒζ�����飬Ʒ��","�ʲݵ���д���һ�","����Ƹеģ������","�������ĵ�","�ľߣ���ֽ","���٣���������׳�ɳ�","���ֻ�","�޷�Ӧ�ģ��䵭��","�ֹ۵ģ����ֵ�","�����ģ�����ȷ��","��࣬ʵ����","����ףԸ","Ƥ����","�ѿڶ���","�ײ�","�������ģ�Ư����","��ŭ�ģ�������","ũ��","��ͣ��","��������Ƥ","���ֵ�","����","��ĳ������ǰ�����ƶ�","�ƾɵ�","ʣ�µ��ˣ�������ʱ��","����","�ʼ磨��ʾ������Į��","��һ�ߵģ����ŵ�","գ��"},
/*unit3*/{"ǿ��Ը����־��","���䣬����","ƫ���ɼ�","��ƫ����","����Ϊ����ɣ�����","�Ļ��ϣ����ĵ�","Ů�Եģ���Ů��","�Ա�","�����"," ��ӵ�","�����ģ��������","���Եģ��������ŵ�","����","���Ա����ӵ�","���Զ�������","�����أ����Ե�","�ж���","���룬�μ�","��ʿ���","ѧ��ǰ��ͯ","��һ�׵ģ�ģʽ����","���ڴ�Ҫ��λ","�޴�ģ�����ģ�ǿ������","���ǹ���ģ����ĵ�","��֪���أ�û��ʶ����","������Ҫ�ģ��ز����ٵ�","���䣬���","���ӣ�����","����","���ӣ�����","���ң�ʹ����","������","���ģ�СƷ��ɢ��","��ϣ����","��ʦ","�鲼������","�Ϸ��ģ�������","���ģ����ҵ�","ȱ����Ů��ȵ�"},
/*unit4*/{"������","������������","�˷����㣬�˷���","��������ֱ��ʵ����","�������","���еģ��к�ʵ�ʵ�","��ͼ���ƻ��������ճ�","��׾��","����","������","̽���ģ������","��������","���棬��Ԥ","���룬���棬��Ԥ","����ģ����ܻ�ӭ��","�ֹ��ģ������ģ��ֲᣬָ��","������ֻ����","��·��","�����ε�","���¶�...�ķ�λ������","�����°�","խ�죬լ��","Ӥ����","�������ڽ�����","ǿ������"},
/*unit5*/{"�˶�Ա","������ͣ���������","�ھ���λ���ھ��ƺ�","���޵ģ����Ƶ�","����������","������ͬ��֧��","�г���Ϣ","��ʵ","����������ֵ������Ҫ���ϳ���","����","���������ӵȣ�����","����ֽ�����ӵȣ���ĳ��ĳ�µĹ�ע","���µģ��ֲ���","�����˶�Ь","��������˿","��ݣ��羴������ŷ�","���򣬻��̨","��Ϊ�أ��˹���","�����˶�","��ʦ","�ھ��������ߣ�ӵ����","�Ը���","�������ģ��¸ҵ�","ʹ�ɻ��Σ�ʹ����","���Ƶģ���λ���µ�","���������������","���ʸ�","����������������","���ģ����","�����أ�������","���ٵأ��Ի͵أ�׳����","������ȭ���֣���ͷ������������","�������ģ�����սʤ��","���ɱ���أ���Ȼ������","���ǣ�ʼ����һ��","��������ģ��Ϸ���","����أ�������","�뷨���ж������","����Ҫ�ģ�����Ҫ��","���ֱ���","����ì�ܣ��������","����ֹ�أ�Ƶ����������������񣩵�","�ܵ���","��Ȩ���Żݣ�����","�����У���Ȩ�Ƶȣ�����Ȩ��","ǿ��","���ۣ�����","�Ϸ��أ�������","�Եģ������йص�","������������","Ӱ��ȫ�ݵģ�ȫ�ݷ�Χ��","���츳�ģ��в��ܵ�","���˵أ� ���ҵأ��м���","������ʤ�ģ����˼�����","ǰ��δ�ŵ�","ƽ���ģ�������ע���"},
/*unit6*/{"��Ӧ�أ�������Ӵ�","װ�׳�","ȷ����,�����Ե�,��ɿ���,��Ȩ����","��ĸ","��¶����¶���ҷ�","������С����һ�㣬����","�ɲ�֢","�ɲ�֢����","�鷳������","ʹ�������壬ʹ���ͣ�����","��","�񾭲�����","����","���ֵģ�ƫ̻�ģ�����ƽ��","���ڿƣ�ҽ��","�����ԣ�����","���ʣ�����","������","ð�յģ��ǳ�Σ�յ�","��ţ���Լ","֢״������","��ʲô��ԣ���ȣ���...��...","�����Ե�","���ڰ���ģ����۸ߵ�","��ȫ���ţ������ӣ�����","���ɱ�����","����̶��ϣ������","ר�����","��ˣ��Ӵ�ʱ��","��ʱ�ԣ�������","�����ʣ�������","������Ǳ����","��Į�ģ������ĵģ�һ���","����Ҫ�ģ��������ص�","ɱ��","��С�ģ���Ҫ��","��Ȼ����","�������","ֵ��ע���","Ӧ֧���ģ���֧����","�����","������","ȫ���ע","��Ҫ��","���������֣��ݶ�","����","��������","һ�٣�������","������","Ŀ���ǳ�ģ����ӵ�","��ȷ�أ�ȷ�е�","�з磬������","�־�","ʱ��ʱ����","�������ģ��������"},
/*unit7*/{"�ʵ��ģ��㹻�ģ���ǿ�����","��ҵ���񣬿�ʼ","������Ҫ��","������Ĩȥ","ȫ���Ա��ϵ���ƣ�ѧԺ���������츳","���룬���󣬻���","���ݵ�","ȷ�еر����룬�ƶ�","�ੲ��ݵ�","ƽӹ��","���п���","���׵ģ�ʡ�µ�","���ӵģ�Σ�յ�","׼���׶ε�","˽��ѧУ��Ԥ��ѧУ","������˵�������ܣ��ṩ������","��װ��αװ","���׷������ˣ���;���ϵ���","����֤�ģ�����","����Ϊ","���ݵģ����̵�","�����ֵģ������ģ����˼�","���ɵģ�������ս��","������������","�׵����跨����","������","���صģ���ɬ�Ѷ���","�Źֵ�","ʹ�˺��µ�","����ģ������","�������;���˵Ļ�������","��ֵģ��޴��ģ�����","����","���µ�","���ܣ�����","�����˷ܵģ�������ܵ�","����ģ��Ϻ���","�۾������","����������","��","���еģ����ݵģ������Ƶģ����е�","��Թ,����,������;����,��Թ","���棬�ֹ���С��˵","��ɬ�Ѷ�����Ϊ��֪��ʹ�����","����ͬ��ģ����õ�","ǰ������������","��ʶ������ʶ����ʵ��","������˼���أ��ظ�","���˲���ģ����õģ��ܲ��","��ѹ�����(���岿��),ѹ,��","���е�","��ο������","���ǣ�ʹ�Ծ���ʹ��ʱ�䣩��������","��ţ��ز�"," ���������˿ڣ�����Һ��"},
/*unit8*/{"��...���Ե���","���ϵģ��Ŷ�","���ﻯѧ��","��Ե����ͷ","ʱ������ѧ","а�̣�ʱ�й��̬��","���ڵģ��ⲿ�ģ����õ�","�����������йص�","����","ʪ�ȣ�ʪ��","����������","�ڲ��ģ����ڵģ����ڵ�","�����ں�֮�ڣ�Χס��Χ��","����ģ��뿪�ģ��Ը������","��֪�ģ��о���","��...������ʽ","����ͬ��","¯��","��ʹ��ͬ��","ͬ��","��ˣ��Ӷ������","����","���ƣ�֧�䣬������ר������","ʹ����ʱ��Լ��","һ�µĻ�Э�����ж�","�ֱ�","�����ģ����Ƶ�","ũѧ�ң�ũҵ��ʦ","����ʶ��","������������������","ְ���൱���ˣ������൱����","���⣬���������Σ�ʧ��","��ʹ��ȫ���Ա����ʹ��","��ȷ�ģ�������","��Ь���࣬�ŵģ����","��Ъ��������г���Ϣ","������ݣ�ת��","����Ը�أ���ǿ��","����������","������ģ������ǵ�","���ȣ�����","���ȵģ����ģ����ޣ�������"},
/*unit9*/{"��Ӧ��ǿ�ģ�����Ӧ��","���գ���⣬���գ����룬���룬��ͬ��","ԭ���ܵģ�ԭ�ӵ�","һ����һȺ��һ��","����","���������ţ���","ͬ...ì�ܣ����������ϣ�����","��ʹ��ת����ʹ���ı�����","�����Եģ�����ģ�ʧ�ܵ�","����ϵأ������ϵ�","���±�׼�����¹淶","�ݱ䣬������","ʵ�飬����","�����μ�����","���䣬�����","�¹���·������·���������","�͹���","����̭�ģ���ʱ��","���٣��ɹ�","ʹ���ױ��","ѧ�ߣ���ѧ������","���֣�Ƭ���ϣ���","������ʹ�","����ĸ��˳���","����","�໥��ϵ������","������","����Ա��������","ʵ���Ե�","ȫϢ��Ƭ","��������˽�ģ����˵ģ���ʾ","���ݣ�����","���ȣ��߶ȣ���������С","���ӵ�","���������Ա","����ѧ�ģ��������Ƶ�","Ҫ������������Ʒ","����","��ʹ��������й���","Сֽ����С����","���ʵģ�����ģ��Ը�ģ�ϲŭ�޳���","�������ţ���Ĥ"},
/*unit10*/{"ͺͷ��","ʫ��","����������","��ǻ","ͻ��,�Ŵ�,����,����������,������","һ�鲼","���ۣ�ע�ͣ�ʵ���������ֳ���˵","��ʹ��������","���ֱ��ŵ�����","����أ������","������ߣ�Ӳ��","�߳ܣ�����","ϰ�����","׿Խ�ģ�������","��ŭ�أ��߿���"," ��ѧ��ʦ����������Ա","С����Ʒ","�ȱ�������","������˵������","������","����������","Ӳֽ��","����ѧ��"," ���","һ�������أ��Ű��","�Źֵģ����Խ��͵�","�ʼǣ���д��","�����߽���������������ĳ��","ɵ�ϣ�����","���ҵģ����ӵ�","�Ʋ⣬�²�","��Զ��","����ʱ��ģ����ݵģ���ʱ�����Ƶ�","ת�ƣ����䣬����","û�б������ģ�δ�Թ���","��ף����ģ����裬����","������������","š�ɣ����֣�������ȡ��ǿ��ȡ��","�к�����д���","ȱϯ��������","�ʿأ��ظ�","�����飬����֤��","ʹ�࣬����","�߾ƾ���ơ�ƣ���ѿ��","�������ϵģ���ʹ���������ϵģ�ʹ��","���ǵ�",
        "����Ժ�����������ӻ���","�޸��ݵ�","����������","ʹ��أ���ŭ��","��թ������","�л�","Ұ�ް�ģ����̵ģ��������˸����","Сľ�ݣ����գ�����","��ѡ�ʸ񣬺򲹵�λ","Ҫ�󣬳�������������","�߳�����ʹ���ﵽ�߳�","�������У�˽Ӫ�����","���ߣ��ѹ�֮��","���������","�����������ģ�������","�����ģ��ɳܵ�","���˾�ɥ�ģ����˻��ĵ�","���","��...��ºţ�����","���ԣ�˵�ѣ������"," ����ģ�����ģ��ۻ��","��ֽ","�ݳ���","����ģ�����","����ɿ��","�����ǽ��","����������Ժ�Ĳ���","Ŀ�ģ���ͼ�������ģ�רע��","˵����","���Ծ�","�뵡�أ��޾���ɵ�","���񲡻��ߣ�����","�������Ƽ���������ָ��","��ס����ס������","��ŭ��","��α֤�ߣ���������","�Ⱥ���Ű��","��","��β��","���͵��ģ����͹��ģ����͵���","���٣����������ԣ�����","�ɳܵ�","�޳ܵ�","�̰�","����ߣ�������","���ɵ�","Ǳ��������","���𣬸���","���ɵģ��ɳܵģ����ӵ�","ͶƱ��ѡ��","�ջأ����������"}
};
//mark���ѹ�  err���������  bingo����ȷ����
short mark[10][100],err[10][100],bingo[10][100];
short If_file_exist;
//�����ݽṹ
struct menu menu;
//��ɫ��
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
//��������
void Put_log(){
    if(If_file_exist){
        FILE *flog = NULL;
        flog = fopen("log.json","w+");
        short unit;
        fprintf(flog,"//���ˣ�����Ϲ��\n");
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
        //�����ǣ����֡�������д����ɫ�����ġ����롢���󡢴��ԣ�
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
//��ȡ����
short Read_log(){
    FILE *flog = NULL;
    flog = fopen("log.json","r");
    if(flog){
        short unit;
        char ban[30];   //���õ�json�ṹ
        fscanf(flog,"%s",ban);//���ˣ�����Ϲ��
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
//��ʼ��
void Ini(){
    int i , j;
    for(i = 0 ; i < 10 ; i++)
        for(j = 0 ; j < 100 ; j++)
            mark[i][j] = err[i][j] = bingo[i][j] = 0 ;
    reciting.repeat = 1;
    If_file_exist = 0;
    Color_ini();
}
//�¹��ܲ�����
void test(){

    printf("%d",Color_twhite);

    getch();
}
//�л�ҳ��
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
        printf("ɶҲû�У���ذ�");
        getch();
        break;
    }
}
//������
int main(){
    //����ʱ��ʼ��
    Ini();
    //������ܴ��ڵ�����
    If_file_exist = Read_log();
    //test();
    while(1){
        //��ҳ-->screen.c
        home();
        //�л�ҳ��
        Change_site();
    }
    return 0;
}





