<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>OnCampus/TCS — Pattern Prep Portal</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link href="https://fonts.googleapis.com/css2?family=Space+Grotesk:wght@500;600;700&family=Inter:wght@400;500;600;700&family=JetBrains+Mono:wght@400;500;700&display=swap" rel="stylesheet">
<style>
:root{
  --bg:#0B0E14; --surface:#12151D; --surface2:#181C26; --surface3:#1E2330;
  --border:#232838; --text:#E7E9EE; --muted:#8A93A6; --muted2:#5D6579;
  --accent:#F2A93B; --accent-dim:#7A5A22; --accent2:#4FD1C5; --accent2-dim:#245C55;
  --danger:#E0596B; --danger-dim:#5c2530;
  --radius:10px; --radius-lg:16px;
  --font-display:'Space Grotesk',sans-serif; --font-body:'Inter',sans-serif; --font-mono:'JetBrains Mono',monospace;
  --shadow:0 8px 30px rgba(0,0,0,.35);
}
html.light{
  --bg:#F6F3EC; --surface:#FFFFFF; --surface2:#FBF9F4; --surface3:#F0ECE2;
  --border:#E2DCCB; --text:#211E18; --muted:#6B6558; --muted2:#8C8672;
  --accent:#B8631A; --accent-dim:#F0D9BC; --accent2:#0F8A7C; --accent2-dim:#CDEAE5;
  --danger:#C13B4F; --danger-dim:#F5D3D8;
  --shadow:0 8px 24px rgba(60,50,30,.12);
}
*{box-sizing:border-box;}
html,body{margin:0;padding:0;}
body{
  background:var(--bg); color:var(--text); font-family:var(--font-body);
  min-height:100vh; -webkit-font-smoothing:antialiased;
}
a{color:inherit; text-decoration:none;}
button{font-family:inherit; cursor:pointer;}
::-webkit-scrollbar{width:10px; height:10px;}
::-webkit-scrollbar-thumb{background:var(--surface3); border-radius:8px;}
::selection{background:var(--accent); color:#100c00;}

/* ---------- layout ---------- */
#app{display:flex; min-height:100vh;}
.sidebar{
  width:230px; flex-shrink:0; background:var(--surface); border-right:1px solid var(--border);
  display:flex; flex-direction:column; position:sticky; top:0; height:100vh; padding:20px 14px; gap:4px;
}
.brand{font-family:var(--font-display); font-weight:700; font-size:17px; padding:6px 8px 18px;}
.brand small{display:block; font-family:var(--font-mono); font-weight:400; font-size:10.5px; color:var(--accent); letter-spacing:.12em; margin-top:3px;}
.navlink{display:flex; align-items:center; gap:10px; padding:10px 12px; border-radius:8px; color:var(--muted); font-size:13.5px; font-weight:600;}
.navlink .dot{width:6px; height:6px; border-radius:50%; background:var(--muted2); flex-shrink:0;}
.navlink:hover{background:var(--surface2); color:var(--text);}
.navlink.active{background:var(--surface3); color:var(--accent);}
.navlink.active .dot{background:var(--accent);}
.sidebar .spacer{flex:1;}
.runway-mini{padding:12px 8px; border-top:1px solid var(--border); margin-top:8px;}
.runway-mini .lbl{font-family:var(--font-mono); font-size:10px; color:var(--muted2); text-transform:uppercase; letter-spacing:.1em; margin-bottom:8px;}
.runway-strip{display:flex; gap:3px;}
.runway-seg{flex:1; height:7px; border-radius:3px; background:var(--surface3);}
.runway-seg.done{background:var(--accent2);}
.runway-seg.today{background:var(--accent); box-shadow:0 0 8px var(--accent);}
.themebtn{margin:8px 8px 0; padding:9px 10px; border-radius:8px; border:1px solid var(--border); background:var(--surface2); color:var(--muted); font-size:12px; font-weight:600; display:flex; align-items:center; gap:8px;}
.themebtn:hover{color:var(--text);}

.main{flex:1; min-width:0;}
.topbar{
  position:sticky; top:0; z-index:20; background:rgba(11,14,20,.82); backdrop-filter:blur(10px);
  border-bottom:1px solid var(--border); display:flex; align-items:center; gap:14px; padding:12px 24px;
}
html.light .topbar{background:rgba(246,243,236,.85);}
.searchwrap{flex:1; max-width:420px; position:relative;}
.searchwrap input{
  width:100%; padding:9px 12px 9px 34px; border-radius:8px; border:1px solid var(--border);
  background:var(--surface2); color:var(--text); font-size:13px; font-family:var(--font-body);
}
.searchwrap input:focus{outline:none; border-color:var(--accent);}
.searchwrap::before{content:'⌕'; position:absolute; left:11px; top:50%; transform:translateY(-50%); color:var(--muted2); font-size:15px;}
.hamburger{display:none; background:none; border:1px solid var(--border); border-radius:8px; padding:8px 10px; color:var(--text);}
.searchresults{position:absolute; top:calc(100% + 6px); left:0; right:0; background:var(--surface2); border:1px solid var(--border); border-radius:10px; max-height:340px; overflow-y:auto; box-shadow:var(--shadow); z-index:30;}
.searchresults .sr-item{display:block; padding:10px 14px; border-bottom:1px solid var(--border); font-size:13px;}
.searchresults .sr-item:last-child{border-bottom:none;}
.searchresults .sr-item:hover{background:var(--surface3);}
.searchresults .sr-tag{font-family:var(--font-mono); font-size:9.5px; color:var(--accent); text-transform:uppercase; letter-spacing:.08em; margin-right:8px;}
.content{padding:26px 30px 70px; max-width:1180px; margin:0 auto;}

/* ---------- shared bits ---------- */
.eyebrow{font-family:var(--font-mono); font-size:11px; letter-spacing:.14em; text-transform:uppercase; color:var(--accent); font-weight:600; margin-bottom:8px; display:flex; align-items:center; gap:8px;}
h1.pagetitle{font-family:var(--font-display); font-size:30px; font-weight:700; margin:0 0 6px; letter-spacing:-.01em;}
p.pagesub{color:var(--muted); font-size:14.5px; margin:0 0 26px; max-width:640px; line-height:1.5;}
.card{background:var(--surface); border:1px solid var(--border); border-radius:var(--radius-lg); padding:20px;}
.grid{display:grid; gap:14px;}
.g2{grid-template-columns:1fr 1fr;} .g3{grid-template-columns:repeat(3,1fr);} .g4{grid-template-columns:repeat(4,1fr);}
.badge{display:inline-flex; align-items:center; gap:5px; padding:3px 9px; border-radius:100px; font-size:11px; font-weight:700; font-family:var(--font-mono); letter-spacing:.02em;}
.badge.p0{background:var(--danger-dim); color:var(--danger);}
.badge.p1{background:var(--accent-dim); color:var(--accent);}
.badge.p2{background:var(--surface3); color:var(--muted);}
.badge.strict{background:var(--danger-dim); color:var(--danger);}
.badge.high{background:var(--accent-dim); color:var(--accent);}
.badge.common{background:var(--surface3); color:var(--muted);}
.freq-meter{display:inline-flex; gap:3px; align-items:center;}
.freq-meter .fd{width:7px; height:7px; border-radius:50%; background:var(--surface3);}
.freq-meter .fd.on{background:var(--accent);}
.section-pill{display:inline-block; padding:2px 9px; border-radius:6px; font-size:10.5px; font-weight:700; font-family:var(--font-mono); text-transform:uppercase; letter-spacing:.06em;}
.pill-quant{background:#2a2410; color:#F2D06B;} .pill-reasoning{background:#151f2e; color:#6BB3F2;}
.pill-verbal{background:#231a2b; color:#C98BE0;} .pill-coding{background:#122a22; color:#4FD1C5;}
html.light .pill-quant{background:#FBEFCB;} html.light .pill-reasoning{background:#DCEBFB;}
html.light .pill-verbal{background:#F0DEF7;} html.light .pill-coding{background:#D3F1EA;}
.btn{display:inline-flex; align-items:center; gap:7px; padding:9px 16px; border-radius:8px; font-size:13px; font-weight:700; border:1px solid var(--border); background:var(--surface2); color:var(--text);}
.btn:hover{border-color:var(--accent);}
.btn.primary{background:var(--accent); color:#150F02; border-color:var(--accent);}
.btn.primary:hover{filter:brightness(1.08);}
.progress-bar{height:7px; border-radius:4px; background:var(--surface3); overflow:hidden;}
.progress-bar > i{display:block; height:100%; background:linear-gradient(90deg,var(--accent2),var(--accent)); border-radius:4px;}
hr.rule{border:none; border-top:1px solid var(--border); margin:26px 0;}

/* ---------- dashboard ---------- */
.stat-row{display:grid; grid-template-columns:repeat(4,1fr); gap:14px; margin-bottom:22px;}
.stat-card{background:var(--surface); border:1px solid var(--border); border-radius:var(--radius-lg); padding:18px;}
.stat-card .num{font-family:var(--font-display); font-size:30px; font-weight:700;}
.stat-card .lbl{font-size:12px; color:var(--muted); margin-top:2px;}
.runway-big{display:flex; gap:5px; margin:16px 0 4px;}
.runway-big .seg{flex:1; height:34px; border-radius:6px; background:var(--surface3); display:flex; align-items:center; justify-content:center; font-family:var(--font-mono); font-size:10px; color:var(--muted2); border:1px solid transparent;}
.runway-big .seg.done{background:var(--accent2-dim); color:var(--accent2); font-weight:700;}
.runway-big .seg.today{border-color:var(--accent); color:var(--accent); font-weight:700; box-shadow:0 0 0 3px var(--accent-dim) inset;}
.topic-row{display:flex; align-items:center; gap:12px; padding:12px 14px; border:1px solid var(--border); border-radius:10px; margin-bottom:9px; background:var(--surface2);}
.topic-row:hover{border-color:var(--accent);}
.topic-row .name{flex:1; font-weight:600; font-size:13.5px;}
.mini-bar{width:80px; height:6px; border-radius:4px; background:var(--surface3); overflow:hidden;}
.mini-bar>i{display:block; height:100%; background:var(--accent2);}

/* ---------- section/topic list ---------- */
.filterbar{display:flex; gap:10px; flex-wrap:wrap; margin-bottom:20px;}
.filterbar select{padding:8px 10px; border-radius:8px; border:1px solid var(--border); background:var(--surface2); color:var(--text); font-size:12.5px; font-family:var(--font-body);}
.topic-card{display:block; background:var(--surface); border:1px solid var(--border); border-radius:var(--radius-lg); padding:18px; margin-bottom:12px; transition:.15s;}
.topic-card:hover{border-color:var(--accent); transform:translateY(-1px);}
.topic-card .row1{display:flex; align-items:center; gap:10px; margin-bottom:8px; flex-wrap:wrap;}
.topic-card .tname{font-family:var(--font-display); font-size:17px; font-weight:700;}
.topic-card .meta-strip{display:flex; gap:16px; font-size:12px; color:var(--muted); font-family:var(--font-mono); margin-top:10px; flex-wrap:wrap;}
.topic-card .meta-strip b{color:var(--text); font-weight:600;}

/* ---------- topic detail page ---------- */
.meta-grid{display:grid; grid-template-columns:repeat(6,1fr); gap:0; border:1px solid var(--border); border-radius:var(--radius-lg); overflow:hidden; margin-bottom:26px;}
.meta-grid .cell{padding:14px 12px; border-right:1px solid var(--border); background:var(--surface);}
.meta-grid .cell:last-child{border-right:none;}
.meta-grid .cell .k{font-family:var(--font-mono); font-size:9.5px; text-transform:uppercase; letter-spacing:.08em; color:var(--muted2); margin-bottom:6px;}
.meta-grid .cell .v{font-weight:700; font-size:13.5px;}
.pattern-row{display:block; border:1px solid var(--border); border-radius:12px; padding:16px 18px; margin-bottom:10px; background:var(--surface);}
.pattern-row:hover{border-color:var(--accent);}
.pattern-row .prow-top{display:flex; align-items:center; gap:12px; margin-bottom:6px;}
.prow-rank{font-family:var(--font-mono); color:var(--muted2); font-size:12px; width:20px;}
.prow-name{font-weight:700; font-size:14.5px; flex:1;}
.prow-check{font-family:var(--font-mono); font-size:10.5px; color:var(--accent2);}
.bottom-nav{display:grid; grid-template-columns:1fr 1fr; gap:14px; margin-top:10px;}
.nav-card{border:1px solid var(--border); border-radius:12px; padding:14px 16px; background:var(--surface);}
.nav-card .k{font-family:var(--font-mono); font-size:10px; text-transform:uppercase; color:var(--muted2); letter-spacing:.08em; margin-bottom:6px;}
.chip-row{display:flex; gap:8px; flex-wrap:wrap;}
.chip{padding:5px 11px; border-radius:100px; background:var(--surface2); border:1px solid var(--border); font-size:12px; font-weight:600;}
.chip:hover{border-color:var(--accent);}

/* ---------- pattern page ---------- */
.p-hero{border:1px solid var(--border); border-radius:var(--radius-lg); padding:22px 24px; margin-bottom:22px; background:linear-gradient(135deg,var(--surface),var(--surface2));}
.p-hero .htop{display:flex; align-items:center; gap:10px; flex-wrap:wrap; margin-bottom:10px;}
.p-hero h1{font-family:var(--font-display); font-size:24px; margin:0 0 4px;}
.confidence-ring{width:64px; height:64px; border-radius:50%; display:flex; align-items:center; justify-content:center; position:relative; flex-shrink:0;}
.confidence-ring .cnum{font-family:var(--font-mono); font-weight:700; font-size:15px;}
.two-col{display:grid; grid-template-columns:1.4fr 1fr; gap:20px; align-items:start;}
@media(max-width:900px){.two-col{grid-template-columns:1fr;}}
.block-title{font-family:var(--font-display); font-size:15px; font-weight:700; margin:0 0 10px; display:flex; align-items:center; gap:8px;}
.block-title::before{content:''; width:3px; height:15px; background:var(--accent); border-radius:2px; display:inline-block;}
.example-box{background:var(--surface2); border:1px solid var(--border); border-radius:10px; padding:14px 16px; font-size:13.5px; line-height:1.55; margin-bottom:14px;}
.var-box{border-left:2px solid var(--accent2); padding:9px 0 9px 14px; margin-bottom:10px; font-size:13px; color:var(--muted); }
.var-box b{color:var(--text); display:block; font-size:12px; font-family:var(--font-mono); color:var(--accent2); margin-bottom:3px;}
.tree{position:relative; padding-left:6px;}
.tree-step{display:flex; gap:12px; position:relative; padding-bottom:20px;}
.tree-step:last-child{padding-bottom:0;}
.tree-step::before{content:''; position:absolute; left:11px; top:26px; bottom:0; width:1px; background:var(--border);}
.tree-step:last-child::before{display:none;}
.tree-num{width:23px; height:23px; border-radius:50%; background:var(--accent2-dim); color:var(--accent2); font-family:var(--font-mono); font-size:11px; font-weight:700; display:flex; align-items:center; justify-content:center; flex-shrink:0; z-index:1;}
.tree-txt{font-size:13.5px; padding-top:2px; line-height:1.5;}
.mistake-item, .trap-box{background:var(--danger-dim); border-radius:8px; padding:10px 13px; font-size:13px; color:var(--text); margin-bottom:8px; border-left:3px solid var(--danger);}
.checklist{display:flex; flex-direction:column; gap:2px;}
.check-item{display:flex; align-items:center; gap:10px; padding:9px 4px; cursor:pointer; border-radius:8px;}
.check-item:hover{background:var(--surface2);}
.check-item input{width:16px; height:16px; accent-color:var(--accent2);}
.check-item span{font-size:13.5px; font-weight:600;}
.check-item.done span{color:var(--accent2); text-decoration:line-through; text-decoration-color:var(--accent2-dim);}
.quiz-q{border:1px solid var(--border); border-radius:10px; padding:14px 16px; margin-bottom:12px; background:var(--surface2);}
.quiz-q .qtext{font-weight:600; font-size:13.5px; margin-bottom:10px;}
.quiz-opt{display:block; width:100%; text-align:left; padding:9px 12px; border-radius:8px; border:1px solid var(--border); background:var(--surface); margin-bottom:6px; font-size:13px; color:var(--text);}
.quiz-opt:hover{border-color:var(--accent);}
.quiz-opt.correct{border-color:var(--accent2); background:var(--accent2-dim); color:var(--accent2); font-weight:700;}
.quiz-opt.wrong{border-color:var(--danger); background:var(--danger-dim); color:var(--danger); font-weight:700;}
.quiz-exp{font-size:12.5px; color:var(--muted); margin-top:8px; padding-top:8px; border-top:1px dashed var(--border);}
.tag-row{display:flex; gap:8px; flex-wrap:wrap; margin-top:14px;}

/* ---------- 15 day plan ---------- */
.day-tabs{display:flex; gap:6px; overflow-x:auto; padding-bottom:10px; margin-bottom:18px;}
.day-tab{flex-shrink:0; padding:9px 14px; border-radius:8px; border:1px solid var(--border); background:var(--surface2); font-family:var(--font-mono); font-size:12px; font-weight:700; color:var(--muted);}
.day-tab.active{background:var(--accent); color:#150F02; border-color:var(--accent);}
.day-tab.complete{border-color:var(--accent2); color:var(--accent2);}
.day-phase{font-family:var(--font-mono); font-size:11px; color:var(--accent); text-transform:uppercase; letter-spacing:.1em; margin-bottom:14px;}
.plan-item{display:flex; align-items:center; gap:12px; border:1px solid var(--border); border-radius:10px; padding:13px 15px; margin-bottom:9px; background:var(--surface);}
.plan-item .pidx{font-family:var(--font-mono); color:var(--muted2); font-size:12px;}
.plan-item .ptitle{flex:1; font-weight:600; font-size:13.5px;}
.plan-item .ptime{font-family:var(--font-mono); font-size:11px; color:var(--muted);}

/* ---------- responsive ---------- */
@media(max-width:880px){
  .sidebar{position:fixed; left:-240px; top:0; height:100vh; z-index:50; transition:.2s; box-shadow:var(--shadow);}
  .sidebar.open{left:0;}
  .hamburger{display:inline-flex;}
  .content{padding:18px 16px 60px;}
  .stat-row{grid-template-columns:1fr 1fr;}
  .meta-grid{grid-template-columns:repeat(3,1fr);}
  .meta-grid .cell:nth-child(3){border-right:none;}
  .two-col{grid-template-columns:1fr;}
  .g2,.g3,.g4{grid-template-columns:1fr;}
  h1.pagetitle{font-size:24px;}
}
.overlay{display:none; position:fixed; inset:0; background:rgba(0,0,0,.5); z-index:40;}
.overlay.show{display:block;}
.empty{text-align:center; padding:50px 20px; color:var(--muted);}
.loading{padding:40px; text-align:center; color:var(--muted); font-family:var(--font-mono); font-size:12px;}
</style>
</head>
<body>
<div id="app">
  <div class="overlay" id="overlay"></div>
  <nav class="sidebar" id="sidebar">
    <div class="brand">OnCampus<span style="color:var(--accent)">/</span>TCS
      <small>PATTERN PREP ENGINE</small>
    </div>
    <div id="navlinks"></div>
    <div class="spacer"></div>
    <div class="runway-mini">
      <div class="lbl">Day Runway</div>
      <div class="runway-strip" id="miniRunway"></div>
    </div>
    <button class="themebtn" id="themeToggle">🌓 Toggle theme</button>
  </nav>
  <div class="main">
    <div class="topbar">
      <button class="hamburger" id="hamburger">☰</button>
      <div class="searchwrap">
        <input type="text" id="searchInput" placeholder="Search patterns, topics… (e.g. Venn, Chain Rule, Pointer)">
        <div class="searchresults" id="searchResults" style="display:none;"></div>
      </div>
    </div>
    <div class="content" id="content"><div class="loading">Loading portal…</div></div>
  </div>
</div>

<script>
/* ============================================================
   DATA LAYER
   ============================================================ */
const SECTIONS = [
  {id:'quant', name:'Quantitative Aptitude', pill:'pill-quant'},
  {id:'reasoning', name:'Logical Reasoning', pill:'pill-reasoning'},
  {id:'verbal', name:'Verbal Ability', pill:'pill-verbal'},
  {id:'coding', name:'DSA & Coding', pill:'pill-coding'},
];

const TOPICS = [
// ---- QUANT ----
{id:'q1', section:'quant', name:'Number System (LCM, HCF, Remainders, Base, Trailing Zeros)', priority:'P1', estQ:'4-6', difficulty:'Medium', studyTime:'2.5 hrs', importance:'Appears in nearly every TCS on-campus slot; remainder-based questions are the single most repeated quant type.', related:['q2'], },
{id:'q2', section:'quant', name:'Proportional Reasoning Core (Ratio → Mixture → % → Profit/Loss → Allegation)', priority:'P0', estQ:'6-9', difficulty:'Medium', studyTime:'4 hrs', importance:'These five "topics" are one reasoning skill in disguise — TCS reuses the same ratio logic across mixture, percentage, and P&L questions.', related:['q1','q6']},
{id:'q3', section:'quant', name:'Time, Work, Pipes & Cisterns', priority:'P0', estQ:'4-5', difficulty:'Medium', studyTime:'2.5 hrs', importance:'Chain rule (M1D1W2=M2D2W1) is asked almost verbatim every cycle — highest ROI pattern in quant.', related:['q4']},
{id:'q4', section:'quant', name:'Time, Speed & Distance', priority:'P0', estQ:'4-5', difficulty:'Medium', studyTime:'2.5 hrs', importance:'Relative-speed meeting-point questions are a strict on-campus staple, almost a reused template.', related:['q3']},
{id:'q5', section:'quant', name:'Permutations, Combinations & Probability', priority:'P0', estQ:'4-6', difficulty:'Hard', studyTime:'3 hrs', importance:'Restricted-selection and probability-of-prediction questions repeat with only numbers changed.', related:['q7']},
{id:'q6', section:'quant', name:'Geometry & Mensuration', priority:'P1', estQ:'3-4', difficulty:'Medium', studyTime:'2 hrs', importance:'Volume-equivalence (melt-and-recast) is a guaranteed template; shadow/height uses the same ratio core as Topic q2.', related:['q2']},
{id:'q7', section:'quant', name:'Data Interpretation & Statistics', priority:'P0', estQ:'3-5', difficulty:'Medium', studyTime:'2 hrs', importance:'3-set Venn diagrams are near-guaranteed; SD-identification is a pure pattern-recognition freebie.', related:['q5']},
// ---- REASONING ----
{id:'r1', section:'reasoning', name:'Number, Letter & Symbol Series', priority:'P0', estQ:'4-6', difficulty:'Medium', studyTime:'2 hrs', importance:'Series questions are guaranteed every slot and reward fast pattern-spotting over calculation.', related:['r2']},
{id:'r2', section:'reasoning', name:'Coding & Decoding', priority:'P0', estQ:'3-5', difficulty:'Medium', studyTime:'2 hrs', importance:'Letter-shift substitution is a strict-on-campus staple with a fixed solving template.', related:['r1']},
{id:'r3', section:'reasoning', name:'Blood Relations', priority:'P0', estQ:'2-3', difficulty:'Medium', studyTime:'1.5 hrs', importance:'Coded symbol-chain questions repeat with the same 4-5 relation symbols reused across papers.', related:['r4']},
{id:'r4', section:'reasoning', name:'Direction Sense', priority:'P0', estQ:'2-3', difficulty:'Easy', studyTime:'1 hr', importance:'Almost always a Pythagorean-distance-after-travel template — very fast marks once recognised.', related:['r3']},
{id:'r5', section:'reasoning', name:'Seating Arrangement & Puzzles', priority:'P0', estQ:'3-5', difficulty:'Hard', studyTime:'2.5 hrs', importance:'Constraint-based grouping puzzles are heavy but guaranteed; slow without a grid method.', related:['r6']},
{id:'r6', section:'reasoning', name:'Decision Making', priority:'P1', estQ:'2-3', difficulty:'Medium', studyTime:'1.5 hrs', importance:'Criteria-matching questions are a checklist exercise, not logic — high accuracy once systematised.', related:['r5']},
// ---- VERBAL ----
{id:'v1', section:'verbal', name:'Vocabulary (Synonyms & Antonyms)', priority:'P0', estQ:'3-5', difficulty:'Easy', studyTime:'2 hrs (spread)', importance:'Pure recall from a fixed high-frequency word list — the fastest marks on the whole paper.', related:['v2']},
{id:'v2', section:'verbal', name:'Sentence & Word Completion', priority:'P0', estQ:'2-4', difficulty:'Medium', studyTime:'1.5 hrs', importance:'Context clues are reused across papers — a small set of "signal words" solves most blanks.', related:['v1']},
{id:'v3', section:'verbal', name:'Error Identification', priority:'P1', estQ:'2-3', difficulty:'Medium', studyTime:'1.5 hrs', importance:'A short list of grammar traps (SVA, prepositions, tense) covers almost all on-campus errors.', related:['v4']},
{id:'v4', section:'verbal', name:'Reading Comprehension', priority:'P1', estQ:'2-3', difficulty:'Medium', studyTime:'1.5 hrs', importance:'True/False/Cannot-Say format rewards literal reading over inference — a trap-avoidance skill.', related:['v3']},
// ---- CODING ----
{id:'c1', section:'coding', name:'Programming Concepts (C/C++ MCQs)', priority:'P0', estQ:'6-8', difficulty:'Hard', studyTime:'3.5 hrs', importance:'Output-prediction MCQs (pointers, loops, macros) are the single biggest coding-section scorer.', related:['c2']},
{id:'c2', section:'coding', name:'Standard Coding (Hands-on)', priority:'P0', estQ:'1', difficulty:'Medium', studyTime:'2 hrs', importance:'One guaranteed easy hands-on question — math/string logic with strict output formatting.', related:['c1']},
{id:'c3', section:'coding', name:'Advanced Coding (Hands-on)', priority:'P1', estQ:'1', difficulty:'Hard', studyTime:'3 hrs', importance:'Story-based competitive programming — lower hit-rate but high differentiator for Digital/Prime.', related:['c2']},
];

// pattern fields: id, topicId, name, freq(1-5), imp('strict'|'high'|'common'), why, rec, tree[], example, variations[3], related, trap, difficulty, mistakes[], skip, time, quiz[]
const PATTERNS = [
// ===== q1 Number System =====
{id:'q1p1', topicId:'q1', name:'Remainder–LCM/HCF Pattern', freq:5, imp:'strict',
 why:'TCS reuses "same remainder / additive-complement remainder" logic because it tests one concept (LCM) via many surface wordings.',
 rec:'If a question gives several divisors AND several remainders, and remainder = divisor − k (same k for all), it is this pattern within 3 seconds.',
 tree:['See multiple divisors + multiple remainders in one line','Check divisor − remainder: same value every time?','Yes → Answer = LCM(divisors) − k, adjust for range given','No → it is a CRT-style problem, solve pairwise'],
 example:'Smallest number between 300–400 divisible by 2,3,4,5,6 leaving remainders 1,2,3,4,5 respectively. Since divisor−remainder=1 always, N = LCM(2,3,4,5,6) − 1 = 59; first multiple of 60 in range: 360−1 = 359.',
 variations:['Same pattern, remainder = divisor − k, but range shifts (e.g. "greatest number below 1000")','Remainders differ but are NOT divisor−k for every term → must solve via CRT pairwise, slower','"Leaves no remainder" version = pure LCM, no adjustment needed'],
 related:'q2p2 (ratio thinking), q1p2',
 trap:'Students often compute LCM and stop — forgetting to subtract k or to find the correct multiple inside the given range.',
 difficulty:'Medium', mistakes:['Forgetting the −k adjustment when divisor−remainder is constant','Picking the LCM itself as the answer instead of the nearest in-range multiple'],
 skip:'Skip only if 3+ divisors are all large primes with no shared structure — rare in TCS, usually a decoy skip.',
 time:'60-75 sec',
 quiz:[
   {q:'Divisors 4,5,6 leave remainders 3,4,5. What is divisor−remainder for each?',opts:['1','2','0','varies'],ans:0,exp:'4-3=1, 5-4=1, 6-5=1 — constant, so this is the LCM−k pattern.'},
   {q:'LCM(4,5,6)=60 and k=1. Smallest such 3-digit number?',opts:['59','119','60','179'],ans:1,exp:'Numbers of form 60m−1: 59 (2-digit, skip), 119 is the smallest 3-digit value.'}
 ]},
{id:'q1p2', topicId:'q1', name:'Base Conversion Pattern', freq:4, imp:'high',
 why:'Tests whether repeated division-remainder logic is automatic — a 100%-procedural pattern TCS likes because it is unambiguous to auto-grade.',
 rec:'Question says "convert to base N" or gives a number already in a non-10 base — instantly a repeated-division (or positional-expansion) task.',
 tree:['Decimal → base N: repeatedly divide by N, collect remainders bottom-up','Base N → decimal: multiply each digit by N^position and sum','Base N → base M (N,M≠10): convert to decimal first, then to M'],
 example:'Convert decimal 678 to base 7: 678÷7=96 r6, 96÷7=13 r5, 13÷7=1 r6, 1÷7=0 r1 → read remainders bottom-up: 1656 (base 7).',
 variations:['Reverse direction: given a base-7 number, convert to decimal','Non-standard base like base-20 or base-3 with the same division method','Arithmetic performed directly inside a non-decimal base (add/multiply in base-N)'],
 related:'q1p1',
 trap:'Reading remainders top-down instead of bottom-up reverses the digit order and gives a wrong-looking-right answer.',
 difficulty:'Easy', mistakes:['Reading the remainder sequence in the wrong order','Stopping division one step early'],
 skip:'Never skip — under 60 seconds once the drill is automatic.',
 time:'45-60 sec',
 quiz:[{q:'What operation converts decimal → base N?',opts:['Repeated multiplication','Repeated division, collect remainders','Digit reversal','Log base N'],ans:1,exp:'Standard method: repeatedly divide by N and read remainders bottom-up.'}]},
{id:'q1p3', topicId:'q1', name:'Trailing Zeros in Factorials', freq:3, imp:'common',
 why:'Tests whether a student knows trailing zeros come from factor pairs of 5 and 2, not brute multiplication — a classic shortcut-recognition filter.',
 rec:'Keyword "number of zeros at the end of N!" or "product of numbers from 1 to N" → count powers of 5.',
 tree:['Identify the question asks for trailing zeros of a factorial/product','Count floor(N/5)+floor(N/25)+floor(N/125)+…','Sum = number of trailing zeros (powers of 2 are always in surplus)'],
 example:'Zeros in 100!: floor(100/5)+floor(100/25)+floor(100/125)=20+4+0=24 zeros.',
 variations:['Product of 1 to N where N is not itself a factorial keyword (disguised factorial)','Asking for trailing zeros in N! for two different N and comparing','Asking "how many 5s in the prime factorization" — same computation, different phrasing'],
 related:'q1p1',
 trap:'Forgetting higher powers of 5 (25, 125…) undercounts zeros for N≥25.',
 difficulty:'Easy', mistakes:['Counting only floor(N/5) and stopping','Confusing powers of 2 with powers of 5 as the limiting factor'],
 skip:'Skip if N>625 and time-pressured — pattern still applies but take last priority under time crunch.',
 time:'40-50 sec',
 quiz:[{q:'Trailing zeros in 50!?',opts:['10','12','8','9'],ans:1,exp:'floor(50/5)+floor(50/25)=10+2=12.'}]},

// ===== q2 Proportional Reasoning Core =====
{id:'q2p1', topicId:'q2', name:'Liquid Replacement (Spoon/Tumbler) Pattern', freq:5, imp:'strict',
 why:'It looks like a mixture problem but is really conservation-of-quantity logic — TCS loves it because most students try to track absolute volumes instead of using the ratio shortcut.',
 rec:'Two containers, a spoon is transferred one way then back → do NOT compute exact concentrations; check what stays invariant instead.',
 tree:['Spot "transfer forward then transfer back" wording','Ask: is total volume in each container restored to original?','If yes → the amount of A in container 2 always equals amount of B in container 1 (symmetry law)','Only compute numbers if the question demands an exact %, not a comparison'],
 example:'Water tumbler and coffee tumbler, equal volumes, one spoon swapped then swapped back. Result: amount of water in the coffee tumbler = amount of coffee in the water tumbler — regardless of spoon size or how many times repeated (as long as volumes return to original).',
 variations:['Multiple swaps repeated several times — the symmetry law still holds after each full round-trip','Different spoon sizes on the forward vs return trip — breaks perfect symmetry, needs real computation','Three containers instead of two — apply the invariant pairwise'],
 related:'q2p2, q2p3',
 trap:'Attempting to calculate exact concentration through algebra when the question only asks a comparison — wastes 90+ seconds for a question answerable by symmetry logic alone.',
 difficulty:'Medium', mistakes:['Solving with full algebra instead of recognizing invariant symmetry','Assuming spoon size matters when volumes are restored'],
 skip:'Never skip — once recognized, solved in under 20 seconds.',
 time:'20-30 sec (symmetry logic) / 90 sec (if exact quantity is asked)',
 quiz:[{q:'Equal volumes, one spoon transferred A→B then same spoon B→A. What is always true?',opts:['A is now purer than B','Amount of A in B = amount of B in A','Impossible to know without spoon size','B is now purer than A'],ans:1,exp:'This is the invariant symmetry law of the spoon-tumbler pattern.'}]},
{id:'q2p2', topicId:'q2', name:'Allegation / Target-Percentage Mixture', freq:4, imp:'high',
 why:'Every "mix two things to hit a target ratio/%" question is solvable by the allegation cross-rule instead of simultaneous equations — TCS rewards knowing the shortcut.',
 rec:'Keywords "in order to make X% / ratio of", two known quantities/concentrations, one unknown amount to add → allegation, not algebra.',
 tree:['Identify the two known concentrations (or parts) and the target %','Draw the allegation cross: (far value − mean) : (mean − near value)','That ratio = ratio of quantities to mix','Solve for the unknown using the given fixed quantity'],
 example:'Mixture has R:S = 2:1. To make S = 25% of mixture, how much R must be added? Current S fraction = 1/3. Target S fraction = 1/4. Use ratio scaling: let R=2,S=1; need S/(R+x+S)=1/4 → 1/(3+x)=1/4 → x=1. Add 1 part R.',
 variations:['Target given as a ratio instead of a percentage — convert first, same cross-rule','Three-component allegation (rare, but reduces to two sequential two-way allegations)','"Removed and replaced" variant — combine with the replacement formula, not pure allegation'],
 related:'q2p1, q2p3, q2p5',
 trap:'Confusing "S is 25% of mixture" with "S:R = 25:75" without re-deriving from current parts — sign errors are common.',
 difficulty:'Medium', mistakes:['Setting up the allegation cross with mean and extreme values swapped','Forgetting to add the new quantity to the denominator when recomputing %'],
 skip:'Skip only under 20 seconds left; otherwise always attemptable in under 90 sec.',
 time:'70-90 sec',
 quiz:[{q:'Allegation cross gives ratio 3:1. What does this ratio represent?',opts:['Ratio of the two concentrations','Ratio of quantities of the two components to mix','Ratio of profit to cost','Final percentage'],ans:1,exp:'The allegation cross output is always the mixing ratio of quantities, not the concentrations themselves.'}]},
{id:'q2p3', topicId:'q2', name:'Successive Percentage Change Pattern', freq:4, imp:'high',
 why:'Tests whether a student multiplies percentage factors correctly instead of adding/subtracting percentages — a very common silent error TCS exploits.',
 rec:'Two or more % changes applied one after another (increase then decrease, or two increases) → multiply (1±p/100) factors, never add the percentages directly.',
 tree:['List each % change in order with correct sign','Convert each to a multiplier: increase p% → (1+p/100), decrease p% → (1−p/100)','Multiply all multipliers together','Net % change = (product − 1) × 100'],
 example:'Price rises 20% then falls 20%. Net change = (1.2)(0.8) − 1 = 0.96 − 1 = −4%, i.e. a net 4% decrease, NOT zero.',
 variations:['Three successive changes (e.g. population growth for 3 years at different rates)','Increase followed by increase (compounding, always > sum of the two %)','"What single % change is equivalent to" — same multiplier method, solve for p'],
 related:'q2p1, q2p2, q2p4',
 trap:'Assuming equal % increase then decrease cancels out to 0% net change — it never does except when p=0.',
 difficulty:'Easy', mistakes:['Adding/subtracting percentages instead of multiplying factors','Sign errors on the decrease multiplier'],
 skip:'Never skip — fastest marks in the whole percentage cluster once the multiplier trick is automatic.',
 time:'30-40 sec',
 quiz:[{q:'A value increases by 10% then decreases by 10%. Net change is:',opts:['0%','-1%','+1%','-10%'],ans:1,exp:'(1.10)(0.90)=0.99 → net change is -1%.'}]},
{id:'q2p4', topicId:'q2', name:'Reverse Percentage Pattern', freq:3, imp:'common',
 why:'Instead of "find the % of a number", TCS often gives the result after a % change and asks for the original — tests inverse-operation fluency.',
 rec:'Question gives a final value AFTER an increase/decrease and asks for the ORIGINAL value → divide by the multiplier, do not apply it forward.',
 tree:['Identify the final value is stated, original is unknown','Determine the multiplier from the stated % change','Original = Final ÷ multiplier (never Final × multiplier)'],
 example:'After a 20% increase, a salary became ₹60,000. Original salary = 60000 / 1.20 = ₹50,000.',
 variations:['Successive reverse (two chained % changes to reverse, apply inverse multipliers in reverse order)','Reverse discount ("selling price is X after Y% discount, find marked price")','Reverse population growth over multiple years'],
 related:'q2p3, q2p5',
 trap:'Multiplying the final value by the same percentage instead of dividing — a very common and costly reversal error.',
 difficulty:'Easy', mistakes:['Multiplying instead of dividing by the multiplier','Applying the % to the final value as if it were the original'],
 skip:'Never skip — always under 45 seconds.',
 time:'30-45 sec',
 quiz:[{q:'A number becomes 90 after a 10% decrease. Original number?',opts:['81','99','100','110'],ans:2,exp:'90 / 0.9 = 100.'}]},
{id:'q2p5', topicId:'q2', name:'Profit–Loss via Ratio Shortcut', freq:3, imp:'common',
 why:'TCS profit/loss questions rarely need absolute cost price — they are solvable through the same ratio/percentage-multiplier logic as q2p3, saving a full algebraic setup.',
 rec:'Given CP:SP ratio, or successive discounts on MP, or "gain%/loss%" phrased as a ratio → treat exactly like successive percentage change on price.',
 tree:['Express profit/loss % as a multiplier on CP to get SP (or vice versa)','If multiple discounts are given, multiply their factors like q2p3','Compare final multiplier to 1 to get net gain/loss %'],
 example:'A shopkeeper marks an item 40% above cost, then gives a 25% discount. Net multiplier = 1.4 × 0.75 = 1.05 → 5% net profit.',
 variations:['Successive discounts only (no markup) — multiply discount factors directly','False weight profit ("uses 900g for 1kg") — convert to an equivalent % profit using the weight ratio','Combined transaction where one item is sold at profit and another at loss — average using weighted ratio, not simple average'],
 related:'q2p3, q2p2',
 trap:'Averaging profit% and loss% directly instead of weighting by cost price when two different items are involved.',
 difficulty:'Medium', mistakes:['Adding markup % and discount % instead of multiplying factors','Simple-averaging two profit/loss percentages on unequal cost bases'],
 skip:'Skip only for false-weight variants if unfamiliar with the conversion formula — otherwise always attempt.',
 time:'50-70 sec',
 quiz:[{q:'Marked up 50%, then 20% discount given. Net profit %?',opts:['30%','20%','15%','25%'],ans:2,exp:'1.5 × 0.8 = 1.2 → 20%... check: 1.5×0.8=1.20 → 20% net profit. (Correct multiplier gives 20%.)'}]},

// ===== q3 Time Work Pipes =====
{id:'q3p1', topicId:'q3', name:'Chain Rule (M1D1W2 = M2D2W1)', freq:5, imp:'strict',
 why:'A single formula covers men-days-work, pipes filling tanks, and machines producing units — TCS reuses the identical structure across "work" questions to test formula transfer.',
 rec:'Sentence structure "X units/people take Y time to do Z work; find time for A units/people to do B work" → chain rule, cross-multiply directly.',
 tree:['Identify the two scenarios: (M1,D1,W1) and (M2,D2,W2)','Write M1×D1×W2 = M2×D2×W1 (rearranged as needed)','Solve for the single unknown'],
 example:'14 programmers take 14 minutes to write 14 lines. How long for 5 programmers to write 5 lines? Since work-per-person-per-minute is constant (1 line/person/min), 5 programmers writing 5 lines still takes 14 minutes (rate doesn\'t change with scale).',
 variations:['Explicit men-days-work numeric version (solve via direct cross-multiplication)','"Work" replaced by "units produced by machines" — identical structure','Trick version where scaling people and work equally keeps time constant (as in the example)'],
 related:'q3p2, q3p3',
 trap:'Auto-applying inverse proportionality without checking that the ratio of people to work is preserved — some TCS versions keep time constant on purpose as a trap.',
 difficulty:'Medium', mistakes:['Not checking whether people and work scale by the same factor (time-invariant case)','Cross-multiplying with mismatched scenario variables'],
 skip:'Never skip — highest ROI single formula in quant.',
 time:'40-60 sec',
 quiz:[{q:'8 workers finish a job in 10 days. How many days for 4 workers?',opts:['5','20','10','40'],ans:1,exp:'Half the workers → double the time: 20 days.'}]},
{id:'q3p2', topicId:'q3', name:'Leaving/Joining Mid-Work Pattern', freq:4, imp:'high',
 why:'Extends the basic rate-addition concept to a timeline where workers enter/exit — tests tracking of work-done-so-far, a common real exam trap.',
 rec:'Multiple workers with individual times, one leaves/joins partway through → split the timeline into before/after segments and track fraction of work completed.',
 tree:['Convert each worker\'s time to a rate (1/time per hour)','Sum rates for the first segment; compute work done = rate×duration','Subtract from 1 to get remaining work','Sum rates for the new (post-change) team; time = remaining work ÷ new combined rate'],
 example:'A(10h), B(12h), C(15h) start together at 11:00. After 2h, A leaves. Combined rate = 1/10+1/12+1/15 = 1/4/hr... (=0.25/hr). Work done in 2h = 0.5. Remaining = 0.5. B+C rate = 1/12+1/15 = 3/20/hr. Time = 0.5÷(3/20)=10/3 h ≈ 3h20m. Finish ≈ 1:00 + 3h20m from 2h mark → finishes at 4:20 PM (13:00+3h20m).',
 variations:['Someone joins mid-way instead of leaving — same method, add rate at the join point','Multiple exits at different times — chain the segments sequentially','Question asks for total work done by one specific person, not total time'],
 related:'q3p1, q3p3',
 trap:'Forgetting to subtract already-completed work before computing the new team\'s remaining time — a very common shortcut skipped by rushed students.',
 difficulty:'Medium', mistakes:['Using the original combined rate for the whole remaining time instead of just the pre-change segment','Arithmetic errors adding three unlike fractions for combined rate'],
 skip:'Skip only if 3+ people join/leave at different times under time pressure — otherwise a reliable pattern.',
 time:'90-120 sec',
 quiz:[{q:'A and B together finish 40% of a job in a fixed time before A leaves. What must you compute next?',opts:['Restart the whole problem','Remaining 60% ÷ B\'s solo rate','A\'s solo time only','Ignore the 40% already done'],ans:1,exp:'Always subtract completed work first, then divide the remainder by the new team\'s rate.'}]},
{id:'q3p3', topicId:'q3', name:'Pipes & Cisterns Combined Rate (incl. Inlet/Outlet)', freq:3, imp:'common',
 why:'Same chain-rule/rate-addition skill as q3p1/q3p2 but with a subtractive twist — an outlet pipe has a negative rate, which is a common conceptual trip point.',
 rec:'Question mentions "fills" and "empties" pipes together, or a leak alongside a fill pipe → treat outlet/leak rate as negative in the sum.',
 tree:['Assign +1/time to every inlet (filling) pipe','Assign −1/time to every outlet/leak pipe','Sum all rates; net time = 1 ÷ |net rate|','If net rate is negative, tank empties instead of fills — reinterpret the question'],
 example:'Pipe A fills in 6h, pipe B empties in 8h, both opened together. Net rate = 1/6 − 1/8 = 1/24/hr → tank fills in 24 hours.',
 variations:['Three pipes, two inlets one outlet — same signed-sum method','Leak develops only after tank is partially full — split into segments like q3p2','"How long would the leak alone take to empty a full tank" — reverse question, same rate model'],
 related:'q3p1, q3p2',
 trap:'Adding the outlet pipe\'s rate as positive instead of subtracting it, which silently makes the tank fill impossibly fast.',
 difficulty:'Easy', mistakes:['Sign error on the outlet/leak rate','Confusing "time to fill" with "time to empty" in the final answer'],
 skip:'Never skip — fast once the signed-rate model is internalized.',
 time:'40-60 sec',
 quiz:[{q:'Inlet fills in 4h, leak empties in 12h. Net time to fill?',opts:['3h','6h','8h','16h'],ans:1,exp:'1/4 − 1/12 = 1/6 → fills in 6 hours.'}]},

// ===== q4 TSD =====
{id:'q4p1', topicId:'q4', name:'Relative Speed — Trains/Objects Meeting', freq:5, imp:'strict',
 why:'A near-identical setup (two moving objects, different start times/speeds, find meeting point/time) is recycled every cycle because relative-speed logic is easy to auto-grade and templated.',
 rec:'Two objects start from two points toward each other (or one chases the other) with a time gap → compute distance already covered, then divide remaining gap by relative speed.',
 tree:['Note the head-start time and use it to compute the "already covered" distance by the earlier starter','Subtract that from total distance to get remaining gap at the moment both are moving','Relative speed = sum of speeds (opposite direction) or difference (same direction)','Time to meet = remaining gap ÷ relative speed; add to the later start time'],
 example:'A and B are 110 km apart. Train from A leaves 7 AM at 20 km/h; train from B leaves 8 AM at 25 km/h. By 8 AM, A has covered 20 km, gap = 90 km. Relative speed = 45 km/h. Time to meet = 90/45 = 2h → they meet at 10 AM.',
 variations:['Same-direction chase (relative speed = difference, not sum)','Circular track meeting (first time together, or first time at starting point) — uses LCM of lap times','Boats & streams version — effective speed changes with current direction (see q4p3)'],
 related:'q4p2, q4p3, r4p1',
 trap:'Forgetting the head-start distance covered before the second object starts moving — this alone changes the "remaining gap" used in the final division.',
 difficulty:'Medium', mistakes:['Using total distance instead of remaining gap after the head start','Adding speeds when objects move in the same direction (should subtract)'],
 skip:'Never skip — extremely high frequency and formulaic once the head-start adjustment is habitual.',
 time:'60-80 sec',
 quiz:[{q:'Objects moving toward each other: relative speed is the ______ of individual speeds.',opts:['difference','sum','product','average'],ans:1,exp:'Opposite-direction relative speed = sum of speeds.'}]},
{id:'q4p2', topicId:'q4', name:'Fuel Consumption / Fractional Comparison', freq:4, imp:'high',
 why:'Tests algebraic fraction-splitting under a total-sum constraint — a lighter cousin of relative speed that trades motion for ratio-of-parts reasoning.',
 rec:'A total quantity is split unevenly between two legs/parts with a stated fractional relationship ("X% more than", "1/4 more") → set up one variable and solve linearly.',
 tree:['Let the smaller/base quantity = x','Express the other quantity in terms of x using the stated fractional relationship','Sum both expressions = given total; solve for x'],
 example:'Round trip uses 4.5 gallons total; going trip uses 1/4 more gasoline than the return trip. Let return = x, going = 1.25x. x + 1.25x = 4.5 → 2.25x = 4.5 → x = 2 gallons used on return.',
 variations:['"More than" replaced by "less than" — same setup with a subtractive fraction','Three-leg trip instead of two — extend the same linear equation','Percentage-based split instead of a simple fraction ("40% more")'],
 related:'q4p1, q2p3',
 trap:'Applying the fractional increase to the total instead of to the smaller/base quantity being compared.',
 difficulty:'Easy', mistakes:['Misassigning which leg is the "more" quantity','Setting up the equation with the fraction applied to the wrong variable'],
 skip:'Never skip — quick linear algebra once the base variable is chosen correctly.',
 time:'45-60 sec',
 quiz:[{q:'"Going trip used 1/4 more than return" means going = ?',opts:['x − 1/4','x','1.25× return','0.75× return'],ans:2,exp:'Going = return + 1/4·return = 1.25×return.'}]},
{id:'q4p3', topicId:'q4', name:'Boats & Streams (Upstream/Downstream)', freq:3, imp:'common',
 why:'A direct application of relative-speed reasoning (q4p1) with current acting as a constant additive/subtractive speed — tests whether students transfer the concept correctly.',
 rec:'Keywords "upstream", "downstream", "current/stream speed" → downstream speed = boat+current, upstream = boat−current.',
 tree:['Extract boat speed in still water (b) and stream speed (s)','Downstream effective speed = b+s; Upstream = b−s','Apply distance/time/speed formula per the question\'s specific ask'],
 example:'Boat speed in still water 10 km/h, current 2 km/h. Downstream speed = 12 km/h, upstream = 8 km/h.',
 variations:['Given downstream and upstream speeds, find boat speed and current speed (reverse: b=(d+u)/2, s=(d−u)/2)','Round trip time comparison between still water and with current','Time to cover the same distance upstream vs downstream, given a time difference'],
 related:'q4p1',
 trap:'Adding current speed when going upstream instead of subtracting — a sign confusion identical in spirit to the q3p3 outlet-pipe trap.',
 difficulty:'Easy', mistakes:['Sign confusion between upstream/downstream','Forgetting to average (d+u)/2 and (d−u)/2 correctly in reverse questions'],
 skip:'Never skip — formulaic and fast.',
 time:'40-50 sec',
 quiz:[{q:'Downstream speed 14, upstream speed 6. Boat speed in still water?',opts:['10','8','4','20'],ans:0,exp:'(14+6)/2 = 10 km/h.'}]},

// ===== q5 PnC Probability =====
{id:'q5p1', topicId:'q5', name:'Restricted Team Selection Pattern', freq:5, imp:'strict',
 why:'"Select a team with an upper/lower bound on one sub-group" is the standard TCS combinatorics template — it tests case-splitting discipline over raw formula memorization.',
 rec:'Selection question with a cap like "not more than k of type A" or "at least k of type A" → split into cases by count of type A and sum combinations.',
 tree:['Identify the total team size and the constrained sub-group','List every valid count of the constrained sub-group (0 to k, or k to max)','For each case, compute nCr(A-count)×nCr(remaining from other group)','Sum all case totals'],
 example:'Team of 11 from 5 men and 11 women, at most 3 men. Sum over men=0,1,2,3: C(5,0)C(11,11)+C(5,1)C(11,10)+C(5,2)C(11,9)+C(5,3)C(11,8).',
 variations:['"At least k" instead of "at most k" — same case-split, different range of cases summed','Two constrained sub-groups simultaneously (rarer, nest the case-split)','"Exactly k" — a single term, no summation needed, easiest sub-case'],
 related:'q5p3, q7p1',
 trap:'Computing only the "exactly k" case when the question says "at most/at least k", missing the required summation across multiple cases.',
 difficulty:'Hard', mistakes:['Solving only one case instead of summing across the valid range','Mixing up nCr with nPr when order does not matter'],
 skip:'Skip only if 3+ nested constraints appear — otherwise always attempt, high mark value.',
 time:'90-120 sec',
 quiz:[{q:'"At most 3 men" in a selection means you must sum cases for men = ?',opts:['exactly 3 only','0,1,2,3','3,4,5','0 only'],ans:1,exp:'"At most 3" includes every count from 0 up to and including 3.'}]},
{id:'q5p2', topicId:'q5', name:'Match/Prediction Probability Pattern', freq:4, imp:'high',
 why:'Tests conditional/joint probability dressed as a story (an animal, a fan, an astrologer "predicting" outcomes) — TCS likes the narrative wrapper to disguise a simple joint-probability multiplication.',
 rec:'A "predictor" guesses an outcome with the SAME probability as the true outcome — the chance the predictor is correct = P(event)² + P(not event)².',
 tree:['Identify P(A) and P(not A) for the actual event','Recognize the predictor picks A with probability P(A) too (matching, not independent guess)','Correct-prediction probability = P(A)×P(A) + P(not A)×P(not A)'],
 example:'Ghana has 2/3 chance to win; Paul picks the winner with the same probability distribution. P(Paul correct) = (2/3)² + (1/3)² = 4/9+1/9 = 5/9.',
 variations:['Predictor probability differs from the true event probability — then it is simple joint multiplication, not squared-sum','Multiple rounds/matches — multiply per-match probabilities for compound event','"Probability predictor is WRONG" — complement of the squared-sum, i.e. 1 − (P(A)²+P(not A)²)'],
 related:'q5p1, q7p2',
 trap:'Treating the predictor\'s pick as independent of the real outcome and just multiplying two unrelated 1/2 probabilities, instead of recognizing the matched-distribution structure.',
 difficulty:'Medium', mistakes:['Ignoring that the predictor\'s probability equals the true event\'s probability (matched distribution)','Adding instead of squaring-then-summing'],
 skip:'Never skip — recognizable within seconds once the "same probability as true outcome" phrase is flagged.',
 time:'50-70 sec',
 quiz:[{q:'True win probability 0.5. Predictor matches this distribution. P(correct prediction)?',opts:['0.5','0.25','1','0.75'],ans:0,exp:'0.5²+0.5² = 0.25+0.25 = 0.5.'}]},
{id:'q5p3', topicId:'q5', name:'Divisible Number Formation Pattern', freq:4, imp:'high',
 why:'Combines digit-formation counting with a divisibility rule (usually by 4 — last two digits) — tests whether a student narrows the search space instead of listing numbers.',
 rec:'"How many N-digit numbers can be formed using digits {...} divisible by 4/5/etc." → apply the divisibility rule to fix the last digit(s), then count freely for the rest.',
 tree:['Identify the divisor\'s rule (by 2: last digit even; by 4: last 2 digits divisible by 4; by 5: last digit 0/5)','Enumerate valid endings from the given digit set that satisfy the rule','Remaining positions can be filled freely (with repetition, by given digits^remaining positions)','Multiply valid-endings count × free-positions count'],
 example:'14-digit numbers from {1,2,3,4,5}, divisible by 4, repetition allowed: fix last two digits to a pair divisible by 4 from the digit set (e.g. 12,24,32,44,52...), count valid pairs, multiply by 5^12 for the remaining 12 free digits.',
 variations:['Divisibility by 2 or 5 (only last digit constrained, simpler)','No repetition allowed — remaining positions use permutations of leftover digits, not free choice','Divisibility by 3 or 9 (digit-sum rule instead of last-digit rule) — different fixing strategy'],
 related:'q5p1, q1p1',
 trap:'Applying a last-digit-only rule (like for 2 or 5) when the divisor is 4, which actually requires checking the last TWO digits.',
 difficulty:'Medium', mistakes:['Using the wrong number of trailing digits for the divisibility rule used','Forgetting repetition is allowed and under-counting free positions'],
 skip:'Skip only if no repetition + high divisor (like 8 or 16) under severe time pressure.',
 time:'70-90 sec',
 quiz:[{q:'Divisibility rule for 4 depends on:',opts:['Last digit only','Last two digits','Digit sum','Last three digits'],ans:1,exp:'A number is divisible by 4 iff its last two digits form a number divisible by 4.'}]},

// ===== q6 Geometry =====
{id:'q6p1', topicId:'q6', name:'Volume Equivalence (Melt & Recast)', freq:5, imp:'strict',
 why:'Tests conservation of volume across shape changes — a single equation (Volume₁ = Volume₂) replaces the need to memorize each shape\'s formula in isolation.',
 rec:'Keywords "melted and recast into", "same volume of material reshaped into" → equate volume formulas of the two shapes and solve for the unknown dimension.',
 tree:['Write the volume formula for the original shape with given dimensions','Write the volume formula for the target shape with the unknown dimension','Set the two volumes equal','Solve algebraically for the unknown (length, radius, or height)'],
 example:'Rectangular plate 8×11×2 in³ melted into a cylindrical rod of diameter 8 in. Volume = 8×11×2 = 176 in³. Rod: π(4)²×L = 176 → L = 176/(16π) ≈ 3.5 in.',
 variations:['Sphere melted into multiple smaller spheres (volume divided equally among n spheres)','Cone/cylinder conversions instead of plate/cylinder','Given final dimension, work backward to find an original dimension'],
 related:'q6p2, q2p2',
 trap:'Using surface area instead of volume, or forgetting that recasting preserves volume, not shape-specific dimensions like surface area or perimeter.',
 difficulty:'Medium', mistakes:['Confusing volume conservation with area/perimeter conservation','Algebra errors isolating the unknown inside a formula with π'],
 skip:'Never skip — one equation, high mark value.',
 time:'60-80 sec',
 quiz:[{q:'Melting and recasting a solid into a new shape conserves its:',opts:['Surface area','Volume','Height','Density only'],ans:1,exp:'Recasting changes shape but the amount of material (volume) stays constant.'}]},
{id:'q6p2', topicId:'q6', name:'Height–Shadow Proportion Pattern', freq:4, imp:'high',
 why:'A pure similar-triangles application dressed as a real-world scenario — same ratio-of-corresponding-sides logic as the Proportional Reasoning Core (q2).',
 rec:'Two objects and their shadows at the same time of day → heights are proportional to their shadow lengths (similar triangles from the same sun angle).',
 tree:['Confirm both shadows are measured at the same time (same sun angle assumed)','Set up height₁/shadow₁ = height₂/shadow₂','Solve the single proportion for the unknown value'],
 example:'Building of height D casts shadow G; neighboring building casts shadow C. Unknown height = D × (C/G).',
 variations:['A person\'s height and shadow used to find a building\'s height via the same ratio (classic "flagpole" version)','Two different times of day mentioned as a decoy — if angles differ, the simple proportion is invalid (rare trap)','Given height ratio, find shadow ratio (reverse direction)'],
 related:'q2p2, q6p1',
 trap:'Applying the proportion when the two shadows are stated at different times of day (different sun angles), which breaks the similar-triangle assumption.',
 difficulty:'Easy', mistakes:['Cross-multiplying with height and shadow of the same object on opposite sides of the ratio','Ignoring a stated time difference that invalidates simple proportionality'],
 skip:'Never skip — one proportion, under 40 seconds.',
 time:'30-40 sec',
 quiz:[{q:'Height-shadow proportionality assumes:',opts:['Same building material','Same time of day (same sun angle)','Same city','Same currency'],ans:1,exp:'Similar triangles from shadows require the same sun angle, i.e. same time of day.'}]},

// ===== q7 DI/Stats =====
{id:'q7p1', topicId:'q7', name:'3-Set Venn Diagram Pattern', freq:5, imp:'strict',
 why:'Nearly every TCS DI slot includes a three-subject overlap question — it tests systematic use of the inclusion-exclusion principle over ad-hoc counting.',
 rec:'Three overlapping groups (subjects, hobbies, languages) with "only", "at least two", "none" phrasing → draw/derive from the inclusion-exclusion formula, fill innermost region first.',
 tree:['List all given values: individual totals, pairwise overlaps, triple overlap, and total universe if given','Start from the centre (all three) and work outward, subtracting shared regions','Compute "only X" as X_total − (X∩Y only) − (X∩Z only) − (X∩Y∩Z)','Cross-check all regions sum to the stated total (or total − none)'],
 example:'90 English, 70 Chemistry, 40 Maths, with given pairwise/triple overlaps → "English only" = English_total − (English∩Chem only) − (English∩Maths only) − (all three), each derived by subtracting the triple overlap from stated pairwise totals first.',
 variations:['Two-set Venn (simpler subtraction, still same subtract-the-overlap logic)','"At least two subjects" asked instead of "only one" — sum all overlap regions instead of isolating one','"None of the three" asked — total universe minus union of all three sets'],
 related:'q5p1, q2p2',
 trap:'Using the given "pairwise overlap" number directly as the "only two" region without first subtracting the triple-overlap count — this is the single most common Venn diagram error.',
 difficulty:'Medium', mistakes:['Not subtracting the triple overlap from pairwise totals before filling the "only two" regions','Sums not matching the given total, indicating a missed or double-counted region'],
 skip:'Never skip — always solvable by building a small region table.',
 time:'100-130 sec',
 quiz:[{q:'A pairwise overlap number given in a 3-set Venn question usually represents:',opts:['Only that pair, excluding the triple overlap','The pair including the triple overlap (needs adjustment)','The full union','Nothing useful'],ans:1,exp:'Given pairwise totals typically include the triple overlap and must be adjusted before filling the "only two" region.'}]},
{id:'q7p2', topicId:'q7', name:'Standard Deviation Identification (No Calculation)', freq:4, imp:'high',
 why:'Rewards conceptual understanding (spread from the mean) over computation — a "spot the answer" pattern designed to be solved without any formula.',
 rec:'Given several small numeric sets and asked "which has highest/lowest SD" → visually judge spread from the mean rather than compute variance formulas.',
 tree:['Compute or estimate the mean of each set quickly','Judge which set has values furthest from its own mean (highest spread) → highest SD','A constant set (all same value) always has SD = 0 → guaranteed lowest'],
 example:'Sets: (a)1,0,1,0,1,0 (b)all −1 (c)all 1 (d)−1,1,−1,1,−1,1. (b) and (c) are constant → SD=0. (a) alternates between 0 and 1 (spread of 0.5 from mean 0.5). (d) alternates between −1 and 1 (spread of 1 from mean 0) → highest SD is (d).',
 variations:['Sets with different means but similar spread — must normalize mentally, not just look at raw range','Asking for lowest SD instead of highest — same estimation, opposite direction','A set with an outlier value — SD dominated by that single point'],
 related:'q7p1',
 trap:'Confusing "biggest range" with "highest standard deviation" — they usually align but not always, especially with clustered vs spread-out middling values.',
 difficulty:'Easy', mistakes:['Computing full variance formula when a 10-second visual comparison suffices','Picking the constant set as highest SD instead of correctly identifying it as zero'],
 skip:'Never skip — fastest marks in the DI section once comfortable with visual estimation.',
 time:'20-30 sec',
 quiz:[{q:'A set where every value is identical has SD equal to:',opts:['1','0','The value itself','Undefined'],ans:1,exp:'No spread from the mean means standard deviation is exactly 0.'}]},

// ===== REASONING =====
{id:'r1p1', topicId:'r1', name:'Alternating / Interleaved Series Pattern', freq:5, imp:'strict',
 why:'TCS frequently interleaves TWO simple sequences into one line to look complex — recognizing the split is the entire skill being tested.',
 rec:'A series that doesn\'t fit one obvious rule when read straight through → try splitting into odd-position and even-position sub-series separately.',
 tree:['Write out positions 1,2,3,4,5,6… under each term','Extract odd-position terms as sub-series A; even-position terms as sub-series B','Find the rule for A alone and for B alone (often each is a familiar simple series)','Apply the correct sub-series rule to find the next term in the right position'],
 example:'1,2,1,3,2,5,3,7,5,11,8,13,13,17… Splitting odd positions: 1,1,2,3,5,8,13 (Fibonacci); even positions: 2,3,5,7,11,13,17 (primes). Next term follows whichever sub-series is next in position.',
 variations:['Three interleaved sub-series instead of two (rarer, check positions mod 3)','One sub-series is arithmetic, the other geometric — mixed rule types','Alternating operations instead of alternating values (e.g. +2, ×2, +2, ×2…)'],
 related:'r1p2, r2p1',
 trap:'Trying to find one single rule across the whole series for too long before testing the odd/even split — wastes 30-40 seconds of the recognition window.',
 difficulty:'Medium', mistakes:['Not testing the odd/even split early enough','Misidentifying which known sequence (Fibonacci, primes, squares) the sub-series matches'],
 skip:'Never skip — recognize within 10 seconds by testing the split immediately if a straight rule fails.',
 time:'40-60 sec',
 quiz:[{q:'A series looks irregular term-by-term. First diagnostic step?',opts:['Give up and guess','Split into odd/even position sub-series','Assume it is random','Only check the last two terms'],ans:1,exp:'Testing an odd/even split is the fastest way to reveal two interleaved simple series.'}]},
{id:'r1p2', topicId:'r1', name:'Letter Cluster Outlier Pattern', freq:5, imp:'strict',
 why:'Tests whether a student can convert letters to numeric positions and spot a broken numeric pattern — a disguised arithmetic-series recognition task.',
 rec:'A group of letter-clusters (often with an attached number) where one doesn\'t follow the same internal rule as the rest → convert letters to A=1…Z=26 and check the arithmetic relationship, including the attached number.',
 tree:['Convert each letter in every cluster to its alphabet position','Find the arithmetic relationship linking the letters to the attached number in each cluster (e.g. product, sum, or difference of positions)','Verify the relationship holds for every cluster','The cluster that breaks the relationship is the outlier'],
 example:'DE19, FH30, IL45, MQ64, RX63, XD62: D=4,E=5 → 4×5=20−1=19; F=6,H=8→6×8=48... testing each reveals which cluster\'s numeric part doesn\'t match its letters\' relationship — that one is the outlier.',
 variations:['Relationship based on sum instead of product of letter positions','Two letters + two-digit number where the number is itself a sub-pattern (squares, primes)','Pure letter clusters with no number, outlier based on skip-pattern (e.g. +1,+2,+3 gaps)'],
 related:'r1p1, r2p1',
 trap:'Assuming the relationship without verifying it against at least 2-3 clusters first — one match doesn\'t confirm the rule.',
 difficulty:'Medium', mistakes:['Testing the rule against only one cluster before committing to it','Off-by-one errors converting letters to numeric positions'],
 skip:'Never skip — always solvable via systematic position-conversion within a minute.',
 time:'60-80 sec',
 quiz:[{q:'First step for a letter-cluster-with-number series?',opts:['Guess based on visual similarity','Convert letters to A=1…Z=26 positions','Ignore the number','Sort alphabetically'],ans:1,exp:'Numeric conversion is required before any arithmetic relationship can be tested.'}]},

{id:'r2p1', topicId:'r2', name:'Letter-Shift Substitution Coding Pattern', freq:5, imp:'strict',
 why:'Tests recognition of a consistent alphabet-shift or substitution rule from one worked example, then applying it to a new word — pure rule-transfer, not memorization.',
 rec:'One word is "coded" as another word of the same length → compare letter-by-letter positional shift (could be constant shift, reverse-alphabet, or paired substitution).',
 tree:['Check if both words are equal length (letter-for-letter substitution likely)','List the alphabet-position difference for each letter pair (coded − original)','If the difference is constant → simple Caesar shift; if it mirrors (A↔Z, B↔Y) → reverse-alphabet substitution','Apply the found rule to the new word to decode/encode'],
 example:'VXUPLVH → SURMISE. Checking position differences per letter often reveals a reverse-alphabet substitution (each letter replaced by its mirror position, e.g. A↔Z, B↔Y…). Apply the same mirror rule to SHDVD to decode it.',
 variations:['Constant forward/backward shift (Caesar cipher) instead of mirror substitution','Words of different lengths — check for a non-letter-for-letter rule (e.g. word reversal, or numeric coding)','Numbers coded as numbers with the same shift logic, instead of letters'],
 related:'r1p2, r2p2',
 trap:'Assuming a simple forward shift without checking for the very common reverse-alphabet (mirror) substitution TCS frequently uses.',
 difficulty:'Medium', mistakes:['Not testing the reverse-alphabet (Z-A mirror) hypothesis when a constant shift doesn\'t fit','Applying the rule in the wrong direction (encode vs decode confusion)'],
 skip:'Never skip — always solvable from the one given example within a minute.',
 time:'50-70 sec',
 quiz:[{q:'If A codes to Z, B to Y, C to X… this substitution is called:',opts:['Caesar shift','Reverse-alphabet (mirror) substitution','Random substitution','Base conversion'],ans:1,exp:'Pairing each letter with its mirror position (A↔Z, B↔Y) is the reverse-alphabet substitution.'}]},
{id:'r2p2', topicId:'r2', name:'Word Rearrangement / Positional Swap Pattern', freq:4, imp:'high',
 why:'Tests careful positional tracking under instructions rather than logic — an attention-to-detail filter dressed as reasoning.',
 rec:'Instructions say "interchange 1st & 2nd letters, 3rd & 4th…" or similar pairwise/segment swaps → physically rewrite the word step by step, don\'t try to do it mentally.',
 tree:['Write out the original word with position numbers below each letter','Apply each swap instruction one at a time, rewriting the word after each step','After all instructions are applied, count from the required end (left or right) to find the asked letter'],
 example:'ORGANISATIONAL: swap (1,2),(3,4),(5,6)… up to the last letter, then find the 10th letter from the right in the resulting word — solved by careful stepwise rewriting, not mental tracking.',
 variations:['Swap instructions apply only to a subset of positions, not the whole word','Reverse a segment of the word instead of pairwise swapping','Multiple rounds of the same swap instruction applied repeatedly'],
 related:'r2p1',
 trap:'Losing track of position after 2-3 swaps and guessing the rest — always rewrite the full word after every single instruction.',
 difficulty:'Medium', mistakes:['Counting position from the wrong end (left vs right) at the final step','Skipping a swap step mentally and compounding position errors'],
 skip:'Skip if the word is long (12+ letters) and time is under 30 seconds remaining — otherwise always attempt with careful rewriting.',
 time:'70-100 sec',
 quiz:[{q:'Best method to avoid errors in multi-step letter swaps?',opts:['Do it mentally, fast','Rewrite the word after each swap step','Skip to the final position directly','Guess based on word length'],ans:1,exp:'Physically rewriting after each step prevents compounding position-tracking errors.'}]},

{id:'r3p1', topicId:'r3', name:'Coded Symbol Blood-Relation Chain', freq:5, imp:'strict',
 why:'Tests whether a student can decode an artificial symbol-language once, then chain multiple relations together — a symbolic-logic-and-family-tree hybrid.',
 rec:'Symbols (+, *, ÷, −, etc.) are redefined as family relations, then a chain like "P☐Q☐R☐S" must be evaluated → decode each symbol first, then build a family tree top-down.',
 tree:['Write down what each given symbol means in plain relation terms (father-of, brother-of, etc.)','Substitute the chain one symbol at a time, building a small family tree/diagram','Track gender where relevant (brother vs sister, father vs mother)','Read off the final relationship asked (e.g. "P is ___ of S")'],
 example:'A+B = A is father of B, A*B = B is brother of A. For P*Q*R*S, decode step by step: Q is brother of P (from P*Q meaning... reading carefully which direction each symbol implies), then extend the tree to R and S, and read the final P-to-S relationship, e.g. brother-in-law.',
 variations:['Symbols redefined differently each time (must always re-decode fresh, never assume standard meanings)','A generation-skip chain (grandfather/grandmother relations appear)','Reverse question — given the final relationship, choose which symbol sequence would produce it'],
 related:'r2p1, r4p1',
 trap:'Assuming symbol meanings carry over from a previous question in the same test — TCS redefines symbols per question, so always re-read the legend.',
 difficulty:'Medium', mistakes:['Reversing the direction of a relation (father-of vs son-of confusion)','Not tracking gender consistently through a long chain'],
 skip:'Never skip — always solvable with a small hand-drawn family tree in under 90 seconds.',
 time:'70-90 sec',
 quiz:[{q:'Best method to solve a coded blood-relation chain?',opts:['Solve purely mentally without notes','Decode each symbol, then sketch a small family tree','Guess based on answer options','Ignore gender information'],ans:1,exp:'A quick hand-drawn tree prevents direction and gender errors across a multi-symbol chain.'}]},

{id:'r4p1', topicId:'r4', name:'Relative Direction & Distance (Right-Angle) Pattern', freq:5, imp:'strict',
 why:'Almost every TCS direction question reduces to a right-triangle distance calculation once movements are plotted on mental axes — tests coordinate visualization over memorized rules.',
 rec:'Movement described in cardinal directions (or turns) over time, then asked "how far / which direction from start" → plot on x-y axes and apply distance formula (often Pythagorean since most turns are 90°).',
 tree:['Assign start point as origin (0,0); set North=+y, East=+x','Convert each described movement into a coordinate change','Sum all coordinate changes to get final position (x,y)','Distance from start = √(x²+y²); direction is read from the sign/quadrant of (x,y)'],
 example:'Two cars start together: one goes East at 10 km/h, one North at 24 km/h, for 3 hours. Positions after 3h: (30,0) and (0,72). Distance apart = √(30²+72²) = √(900+5184)=√6084=78 km.',
 variations:['Multiple turns (not just two directions) — accumulate coordinates step by step','Question asks for direction (bearing) instead of distance — use the quadrant/angle of final (x,y)','A return-journey or "shortest distance to start" variant'],
 related:'r3p1, q4p1',
 trap:'Adding distances directly instead of treating perpendicular directions (like East and North) as forming a right triangle requiring Pythagoras.',
 difficulty:'Easy', mistakes:['Simply summing distances traveled instead of computing straight-line distance between final coordinates','Sign errors when a movement reverses direction (e.g. "turns back")'],
 skip:'Never skip — fastest, most template-driven pattern in reasoning.',
 time:'40-60 sec',
 quiz:[{q:'Two people move perpendicular to each other from the same start. Distance between them is found using:',opts:['Simple addition','Pythagorean theorem','Average of distances','Multiplication of distances'],ans:1,exp:'Perpendicular displacements form a right triangle; hypotenuse = straight-line distance.'}]},

{id:'r5p1', topicId:'r5', name:'Constraint-Based Group/Seating Allocation', freq:5, imp:'strict',
 why:'Tests systematic elimination against multiple simultaneous constraints — TCS deliberately gives more constraints than needed for one deduction to force a structured, not guessed, approach.',
 rec:'Multiple entities with group memberships and adjacency/exclusion rules, then asked "which arrangement/order is valid" → build a grid or slot diagram and eliminate options against each rule one at a time.',
 tree:['List every entity and its group/category membership from the passage','List every constraint as a short rule ("no two from same game sit together", etc.)','For "which of the following is possible" questions, test each option against every rule in turn, eliminating on first violation','For "must be true" questions, deduce fixed positions first, then infer the rest'],
 example:'Players from Football (H,M,O) and Basketball (K,N) must not have two same-game players adjacent. Test each answer-choice seating order against this single rule, eliminating any order with two Football or two Basketball players next to each other.',
 variations:['Circular seating instead of linear (positions "adjacent" wrap around)','Multiple constraint types combined (adjacency + fixed position + facing direction)','Question asks to identify what CANNOT be true, rather than what must/can be true'],
 related:'r6p1, r3p1',
 trap:'Trying to build one single valid full arrangement from scratch instead of testing given answer options directly against the constraints — direct option elimination is almost always faster.',
 difficulty:'Hard', mistakes:['Not checking every constraint against an option before accepting it (stopping after the first rule)','Missing that seating is circular when it changes which seats count as adjacent'],
 skip:'Skip if severely time-pressured and 4+ constraints are given with no options to test against — otherwise always attempt via elimination.',
 time:'120-150 sec',
 quiz:[{q:'Fastest approach for "which of these seating orders is possible" questions?',opts:['Build the full arrangement from scratch first','Test each given option against every constraint, eliminating violators','Pick the first option that seems reasonable','Ignore constraints not mentioned in the question stem'],ans:1,exp:'Direct elimination of given options against all constraints is faster than deriving from scratch.'}]},

{id:'r6p1', topicId:'r6', name:'Candidate Selection Criteria Matching', freq:5, imp:'strict',
 why:'Tests careful, literal rule-application against a candidate profile — a checklist-matching skill, not abstract logic, so accuracy depends on not skipping any criterion.',
 rec:'A numbered list of eligibility criteria followed by one or more candidate profiles → check the profile against EVERY criterion in order, including "except" clauses referred to a manager/committee.',
 tree:['List every numbered criterion separately','Go through the candidate profile attribute by attribute, matching each to a criterion','Note any criterion the profile fails; if none fail, candidate is selected','If a "refer to [role]" exception clause exists and one specific condition is met, apply that alternate outcome instead of a flat reject'],
 example:'Criteria: graduate with min 68%, or post-grad with 70%, age ≤ 27, except cases referred to the manager. Check Mr. Mohit\'s profile against each criterion in sequence; if he fails on age alone but an exception clause applies, the outcome is "referred to manager", not simply "rejected".',
 variations:['Multiple candidates evaluated against the same criteria set in one sitting','Criteria include a compound AND/OR condition (e.g. "either X or Y, plus Z")','A borderline case designed to test the exact threshold value (e.g. exactly 68%, not 67.9%)'],
 related:'r5p1',
 trap:'Stopping evaluation after the first failed criterion without checking whether an exception/referral clause changes the outcome from "rejected" to "referred".',
 difficulty:'Medium', mistakes:['Missing an "except, refer to manager" style clause and marking straight rejection','Misreading boundary values (≥ vs >) on cutoff percentages or age'],
 skip:'Never skip — accuracy-based, not difficulty-based; always attempt with a careful line-by-line check.',
 time:'60-90 sec per candidate',
 quiz:[{q:'A candidate fails one criterion, but an "except, refer to manager" clause applies. Correct outcome?',opts:['Selected','Rejected','Data insufficient','Referred to manager, not flat-rejected'],ans:3,exp:'Exception clauses override a flat rejection with the specified alternate outcome.'}]},

// ===== VERBAL =====
{id:'v1p1', topicId:'v1', name:'Direct Synonym/Antonym Recall Pattern', freq:5, imp:'strict',
 why:'Pure vocabulary recall from a repeated high-frequency word pool — TCS reuses the same ~200-300 words across cycles, making pre-learning the list the entire strategy.',
 rec:'A single bolded/capitalized word with 4 options → this is always solved by pre-memorized meaning, never by context (there is no sentence to infer from).',
 tree:['Recognize the question gives an isolated word, not a sentence','Recall the word\'s core meaning from your studied high-frequency list','Match to the closest option (synonym) or exact opposite (antonym)','If unsure, eliminate options that are clearly unrelated in tone/connotation first'],
 example:'CIRCUMSPECT → options: condition, inspect, cautious, reckless. Correct synonym: cautious (circumspect = careful/wary of consequences).',
 variations:['Antonym instead of synonym — same recall method, opposite meaning required','Word with multiple meanings — TCS usually intends the more common/formal meaning','Options include a near-miss word with a different connotation (positive vs negative) as a distractor'],
 related:'v2p1',
 trap:'Selecting a word that sounds phonetically similar to the answer rather than one that matches the actual meaning (a very common surface-level distractor).',
 difficulty:'Easy', mistakes:['Confusing a word with a similar-sounding but unrelated word','Not eliminating options with opposite connotation before choosing'],
 skip:'Never skip — fastest possible marks if the word is known; otherwise educated-guess by connotation (positive/negative) and move on within 15 seconds.',
 time:'10-20 sec',
 quiz:[{q:'CIRCUMSPECT most nearly means:',opts:['Reckless','Cautious','Curious','Circular'],ans:1,exp:'Circumspect = wary and careful, i.e. cautious.'}]},
{id:'v2p1', topicId:'v2', name:'Contextual Signal-Word Placement Pattern', freq:5, imp:'strict',
 why:'Tests recognition of small connector/signal words (however, therefore, despite) that dictate logical flow — a fill-in-the-blank shortcut that avoids needing full comprehension.',
 rec:'A blank sits right after or before a logical connector, or the sentence structure implies a contrast/continuation → identify the logical relationship needed (agreement, contrast, cause-effect) before checking word options.',
 tree:['Read the sentence around the blank ignoring the options first','Decide whether the blank needs a word that continues, contrasts, or explains the prior idea','Eliminate any option that reverses that required logical direction','Pick the option matching both logical direction AND grammatical fit'],
 example:'"New industries...[Blank1] offer better salaries...They need talented people and [Blank2] are willing to pay high wages." Blank1 likely needs a word implying ability/tendency (e.g. "can"), Blank2 needs a continuing/causal connector (e.g. "so" or "therefore") matching the cause-effect flow.',
 variations:['Cloze passage with 4-5 sequential blanks, each depending on the previous sentence\'s established tone','Blank requires a word matching formal register (avoid casual synonyms)','Two blanks where the second depends grammatically on the word chosen for the first'],
 related:'v1p1, v3p1',
 trap:'Picking a word that is grammatically correct in isolation but breaks the logical flow (contrast vs continuation) established by the surrounding sentence.',
 difficulty:'Medium', mistakes:['Choosing options based on grammar alone without checking logical direction','Not reading the full surrounding sentence before evaluating options'],
 skip:'Never skip — always solvable by logical-direction elimination even without full vocabulary certainty.',
 time:'30-45 sec per blank',
 quiz:[{q:'A sentence uses "however" before the blank. The blank likely needs to:',opts:['Continue the same idea','Introduce a contrasting idea','Repeat the previous word','Be irrelevant to context'],ans:1,exp:'"However" signals a contrast, so the blank must introduce an opposing or contrasting idea.'}]},
{id:'v3p1', topicId:'v3', name:'Grammar/Phrasal Error Spotting Pattern', freq:4, imp:'high',
 why:'Tests recognition of a small fixed set of grammar traps (subject-verb agreement, tense mixing, preposition misuse) rather than deep grammar theory — a checklist skill.',
 rec:'A sentence split into 3-4 labeled parts, asking which part has an error → scan each part specifically for SVA, tense consistency, and preposition correctness, in that priority order.',
 tree:['Check subject-verb agreement in each part (singular/plural match)','Check tense consistency across all parts of the sentence','Check preposition usage in each part (common fixed pairings)','If all three checks pass, consider article usage or redundant wording as the last check'],
 example:'"...everyone will take the examination now..." — checking tense: if surrounding parts use future tense but this part inconsistently mixes present/future incorrectly, or "everyone" (singular) is paired with a plural verb form elsewhere, that flags the error part.',
 variations:['Error is a missing/extra article ("a", "the") rather than SVA or tense','Idiomatic preposition error (e.g. "married with" instead of "married to")','No error at all — one option is "no error", tests overconfidence in finding a flaw'],
 related:'v2p1, v4p1',
 trap:'Assuming there must be an obvious error and overlooking that "no error" is sometimes the correct choice.',
 difficulty:'Medium', mistakes:['Fixating on style/wordiness instead of an actual grammar rule violation','Missing subtle singular/plural subject-verb mismatches with collective nouns'],
 skip:'Never skip — checklist-based and fast once the SVA→tense→preposition order is habitual.',
 time:'40-60 sec',
 quiz:[{q:'Priority order for spotting a grammar error in a split sentence?',opts:['Vocabulary difficulty first','Subject-verb agreement, then tense, then prepositions','Randomly guess a part','Sentence length'],ans:1,exp:'SVA, tense consistency, and preposition usage cover the vast majority of on-campus grammar errors, checked in that order.'}]},
{id:'v4p1', topicId:'v4', name:'True/False/Cannot-Say Literal Inference Pattern', freq:4, imp:'high',
 why:'Tests literal-reading discipline over outside knowledge or assumption — the trap is answering based on general belief rather than exactly what the passage states.',
 rec:'A statement is given after a short passage with options True/False/Cannot-Say → check ONLY what the passage explicitly states or directly implies, ignoring outside knowledge or plausible-sounding inference.',
 tree:['Re-read only the passage lines relevant to the statement\'s topic','Ask: does the passage explicitly confirm this statement? → True','Ask: does the passage explicitly contradict this statement? → False','If the passage neither confirms nor denies it (topic not addressed, or insufficient detail) → Cannot Say'],
 example:'"Even with fast tech developments we cannot live happily" — unless the passage explicitly makes this exact causal claim about happiness and technology, the correct answer is typically Cannot Say, since it goes beyond what a factual/technical passage usually states.',
 variations:['Statement is a partial truth (passage confirms part but not all of it) → usually Cannot Say, not True','Statement uses stronger/absolute language ("always", "never") than the passage\'s hedged claim → False or Cannot Say depending on contradiction','Statement paraphrases the passage closely enough to count as True'],
 related:'v3p1',
 trap:'Answering based on general world knowledge or personal opinion about the topic instead of strictly what the passage states.',
 difficulty:'Medium', mistakes:['Confusing "not mentioned" with "False" when it should be "Cannot Say"','Over-trusting a statement that merely sounds plausible given the passage\'s general topic'],
 skip:'Never skip — accuracy-focused rather than time-costly once the confirm/contradict/absent framework is used strictly.',
 time:'40-60 sec per statement',
 quiz:[{q:'Passage never mentions a topic the statement asks about. Correct answer is usually:',opts:['True','False','Cannot Say','Depends on the reader\'s opinion'],ans:2,exp:'If the passage neither confirms nor denies the statement, the literal-inference answer is Cannot Say.'}]},

// ===== CODING =====
{id:'c1p1', topicId:'c1', name:'Pointer / Post-Increment Output Prediction', freq:5, imp:'strict',
 why:'Tests precise understanding of operator precedence and evaluation order (post-increment vs pre-increment, logical NOT) — a classic C-language trap TCS recycles heavily.',
 rec:'printf/cout statement mixing a variable with ++/-- and logical/arithmetic operators in the SAME expression → evaluate strictly left-to-right per C\'s argument evaluation and operator precedence rules, tracking the value used vs the value stored.',
 tree:['Identify each occurrence of the variable and whether it uses pre-(++x) or post-(x++) increment','For post-increment, use the OLD value in the current expression, then increment after','Evaluate any logical NOT (!) or arithmetic on the used (old) value','Determine final printed values matching each argument\'s evaluated-at-that-moment value'],
 example:'`int a=5; printf("%d %d", a, !a++);` — the second argument uses the OLD value of a (5) for the NOT operation: !5 evaluates to 0 (since 5 is non-zero/truthy). a is then incremented to 6 after, but since printf argument evaluation order is unspecified in strict C standard, TCS expects the commonly assumed right-to-left practical evaluation: output is often "6 0" or "5 0" depending on compiler assumption taught — the key testable concept is that !a++ uses a\'s pre-increment value for the NOT.',
 variations:['Function calls with side-effects appearing multiple times in one expression (same precedence trap, different operators)','Combination of pre- and post-increment on the same variable in one statement','Nested increments inside array indexing (a[i++] vs a[++i])'],
 related:'c1p2, c1p3',
 trap:'Assuming left-to-right evaluation of printf arguments is guaranteed by the C standard — it is compiler-dependent, but TCS MCQs expect the commonly-taught convention, so match the taught convention rather than argue standard-compliance.',
 difficulty:'Hard', mistakes:['Using the incremented value instead of the pre-increment value for post-increment operations within the same expression','Ignoring operator precedence between logical NOT and increment operators'],
 skip:'Skip only if the expression mixes 3+ increments/decrements of the SAME variable in one line (real ambiguity even for experts) — otherwise always attempt.',
 time:'45-70 sec',
 quiz:[{q:'In `x++`, which value is used in the CURRENT expression?',opts:['The value after incrementing','The value before incrementing (old value)','Undefined always','Zero'],ans:1,exp:'Post-increment (x++) uses the old value in the current expression; the increment happens after.'},
       {q:'`!5` (logical NOT of a non-zero value) evaluates to:',opts:['5','1','0','-1'],ans:2,exp:'Logical NOT of any non-zero (truthy) value is 0.'}]},
{id:'c1p2', topicId:'c1', name:'Loop / Modulus Tracing Pattern', freq:5, imp:'strict',
 why:'Tests careful hand-tracing of a small function across repeated calls — a discipline check for following state changes exactly rather than guessing the output.',
 rec:'A small recursive-looking or repeatedly-called function using modulus/parity checks → manually trace variable state through EACH call in sequence, writing down the value after every line.',
 tree:['Write down the initial value of every variable before the first call','Step through the function body for the first call, noting the returned/modified value','Feed that returned value as input to the next call (if chained)','Repeat until all calls are traced; the final printed value is the answer'],
 example:'`func(int i){ if(i%2) return 0; else return 1; } main(){ int i=3; i=func(i); i=func(i); printf("%d",i); }` — first call: i=3, 3%2=1 (true) → returns 0. i becomes 0. Second call: i=0, 0%2=0 (false) → returns 1. i becomes 1. Printed value: 1.',
 variations:['Recursive function calling itself (trace a call stack instead of sequential calls)','Loop with a break/continue condition based on modulus','Multiple variables updated across iterations, not just one'],
 related:'c1p1, c1p4',
 trap:'Skipping ahead and guessing the pattern after one iteration instead of tracing every single call/iteration explicitly — small functions often have a non-obvious short cycle.',
 difficulty:'Hard', mistakes:['Not re-evaluating the condition with the UPDATED variable value on each subsequent call','Sign/truthiness confusion around "if(i%2)" (true when i is odd, since result is 1, not 0)'],
 skip:'Never skip — always solvable by disciplined manual tracing within a minute.',
 time:'50-80 sec',
 quiz:[{q:'`if(i%2)` is true (non-zero) when i is:',opts:['Even','Odd','Zero','Negative only'],ans:1,exp:'i%2 equals 1 (truthy) for odd i, and 0 (falsy) for even i.'}]},
{id:'c1p3', topicId:'c1', name:'Core C Definitions (Structs/Unions/Macros) MCQ Pattern', freq:4, imp:'high',
 why:'Tests textbook-level factual correctness about C language constructs — a pure knowledge-recall pattern with no calculation, high accuracy potential if concepts are reviewed once.',
 rec:'"Which of the following statements is INCORRECT regarding [struct/union/macro/typedef]" → recall the precise definitional rule for that construct rather than reasoning from first principles under time pressure.',
 tree:['Identify which construct is being asked about (struct, union, macro, typedef, enum)','Recall its 2-3 defining properties (e.g. struct: each member has separate memory; union: members share memory)','Check each option against those defining properties one at a time','Select the option that violates a defining property'],
 example:'`typedef struct new { int n1; char n2; } DATA;` — questions typically test whether DATA is a type alias for the struct (true), whether "struct new" can still be used standalone (true), or whether members overlap in memory like a union (false — struct members do NOT share memory, unlike union).',
 variations:['Union memory-sharing property tested instead of struct','Macro expansion/text-substitution pitfalls (missing parentheses causing operator precedence bugs)','Enum default value and increment behavior'],
 related:'c1p1, c1p4',
 trap:'Confusing struct (separate memory per member) with union (shared memory across members) — the most common conceptual mix-up in this pattern.',
 difficulty:'Medium', mistakes:['Mixing up struct vs union memory layout rules','Misremembering macro expansion as function-call semantics (macros are text substitution, no type-checking)'],
 skip:'Never skip — pure recall, no time cost if concepts are reviewed beforehand.',
 time:'30-45 sec',
 quiz:[{q:'In a union, all members:',opts:['Have separate memory','Share the same memory location','Cannot be accessed at all','Must be the same type'],ans:1,exp:'Union members overlap in memory; only one member holds a valid value at a time.'}]},
{id:'c1p4', topicId:'c1', name:'Memory Allocation (Stack/Heap/Static) Pattern', freq:4, imp:'high',
 why:'Tests basic understanding of where different kinds of data live in memory — a foundational OS/C concept TCS checks via simple direct-recall MCQs.',
 rec:'Question asks "where is X allocated" (malloc, local variable, static variable, global variable) → map the specific keyword/function directly to its standard memory region.',
 tree:['Identify the allocation method or variable type mentioned (malloc/new, local, static, global)','Recall: malloc/new → heap; local variables → stack; static/global → static/data segment','Match the option that correctly names this region'],
 example:'`malloc()` allocates memory in the heap area (dynamically, until explicitly freed), not the stack (which holds local variables and function call frames) or static area (which holds global/static variables for the program\'s lifetime).',
 variations:['Local variable location (stack) instead of malloc (heap)','Static/global variable location (data/static segment)','Function call frame / return address location (also stack)'],
 related:'c1p3',
 trap:'Confusing heap (dynamic, malloc/free) with stack (automatic, local variables) — the single most common memory-region mix-up.',
 difficulty:'Easy', mistakes:['Assuming malloc allocates on the stack','Confusing static storage duration with heap allocation'],
 skip:'Never skip — pure recall, fastest marks in the MCQ set.',
 time:'20-30 sec',
 quiz:[{q:'`malloc()` allocates memory in the:',opts:['Stack','Heap','Static/data segment','CPU register'],ans:1,exp:'malloc() dynamically allocates memory on the heap.'}]},

{id:'c2p1', topicId:'c2', name:'Mathematical Function Logic (Hands-on Coding)', freq:5, imp:'strict',
 why:'Tests the ability to translate a simple math definition (factorial, prime check, digit sum) into correctly-formatted code, with strict output-format grading — TCS auto-graders reject any extra text/whitespace.',
 rec:'A hands-on question asks to compute a well-known math function from a command-line/input argument → write the simplest correct loop/recursion AND strictly match the required output format (no extra text, correct data type).',
 tree:['Parse the input exactly as specified (command-line argument, stdin, or function parameter)','Implement the simplest correct loop or recursive solution for the math function','Print ONLY the required output value, with no extra labels, spaces, or newlines beyond what is asked','Test with edge cases: 0, 1, and a typical middle value'],
 example:'"Calculate factorial of non-negative integer N, output must be formatted as an integer WITHOUT any other additional text." → read N, compute product 1×2×...×N (handle N=0 → 1), print ONLY the numeric result, no extra "Answer:" label or trailing newline text.',
 variations:['Prime checking or digit-sum instead of factorial — same input/strict-output discipline','Recursive vs iterative implementation choice (either accepted, but recursion risks stack overflow on large N)','Output required as a specific type (e.g. long long for large factorials) — overflow-awareness needed'],
 related:'c1p1, c2p2',
 trap:'Adding a descriptive label or extra whitespace/newline to the output ("Factorial is: 120" instead of just "120") — this fails TCS\'s strict auto-grader even if the logic is fully correct.',
 difficulty:'Medium', mistakes:['Printing extra text/labels around the numeric answer','Not handling edge cases like N=0 (factorial of 0 is 1) or negative input validation'],
 skip:'Never skip — this is the single guaranteed easy hands-on mark; always attempt fully.',
 time:'8-12 min',
 quiz:[{q:'TCS hands-on output grading is typically:',opts:['Lenient about extra text','Strict — exact match required, no extra text','Based on code style only','Ignored if logic is correct'],ans:1,exp:'TCS auto-graders require exact output matching; any extra text or formatting causes a fail even with correct logic.'}]},
{id:'c2p2', topicId:'c2', name:'String Manipulation / Substring Replace Pattern', freq:4, imp:'high',
 why:'Tests careful index-based string traversal and in-place/new-string construction — a fundamental string-handling skill TCS checks via a "find and replace" style task.',
 rec:'Given a string and a substring to find-and-replace with another substring → scan for all occurrences of the target substring and build a new output string with replacements, handling length differences carefully.',
 tree:['Read the main string, the substring to find, and its replacement','Scan the main string for every occurrence of the target substring (handle overlapping occurrences per spec)','Build the result string by copying non-matching parts and substituting matched parts with the replacement','Print the final resulting string, exactly formatted as specified'],
 example:'str1="anil samal", str2="sa", str3="b": scanning for "sa" finds one occurrence in "samal" → replace to get "anil bmal".',
 variations:['Multiple occurrences of the substring throughout a longer string','Case-sensitivity specified or not specified (clarify assumption, default to case-sensitive if unstated)','Replacement string longer or shorter than the original substring (careful index/length bookkeeping)'],
 related:'c2p1',
 trap:'Off-by-one errors when the replacement substring has a different length than the original, shifting subsequent match positions if using a single mutable buffer instead of building a new string.',
 difficulty:'Medium', mistakes:['Not handling multiple occurrences of the target substring','Index errors when replacement length differs from the original substring length'],
 skip:'Never skip — a standard, always-attemptable string task.',
 time:'8-12 min',
 quiz:[{q:'When replacement length differs from the original substring, the safest approach is:',opts:['Modify the string in-place character by character','Build a new result string by copying and substituting as you scan','Ignore the length difference','Only handle same-length replacements'],ans:1,exp:'Building a new string avoids index corruption when lengths differ.'}]},

{id:'c3p1', topicId:'c3', name:'Story-Based Path/Logic Puzzle (Competitive Programming)', freq:5, imp:'strict',
 why:'Wraps a graph/array/math algorithm in a narrative (houses, rooms, a puzzle-setting owner) to test whether a student can strip the story and identify the underlying algorithmic structure — pattern recognition under narrative disguise.',
 rec:'A long story describing rooms/paths/a puzzle with a numeric goal → ignore the narrative flavor text first, extract the actual inputs, constraints, and the mathematical/array operation being asked, then map it to a known algorithm category (DP, greedy, simulation, graph traversal).',
 tree:['Read once for narrative understanding, then re-read purely to extract: inputs, constraints, and the exact output required','Classify the underlying problem type (simulation, DP, greedy, graph/array traversal)','Write pseudocode for that known algorithm category using the extracted variables, ignoring story flavor entirely','Code and test against the story\'s own worked example before submitting'],
 example:'"The Golden House Puzzle": N rooms, an owner sets a puzzle to hire a manager — stripped of narrative, this is typically an array/index simulation or DP problem (e.g. finding an optimal room/path satisfying a numeric condition) — solve the extracted algorithmic core, not the story.',
 variations:['Graph/path-finding narrative (shortest path, connectivity) — map to BFS/DFS/Dijkstra template','Array/DP narrative (maximize/minimize a value under constraints) — map to a DP recurrence','Simulation narrative (step-by-step process with state changes) — map to a straightforward loop-based simulation'],
 related:'c2p1, c3p2',
 trap:'Spending too much time trying to solve the problem AS the story describes it (tracking narrative details) instead of abstracting to the underlying algorithm immediately.',
 difficulty:'Hard', mistakes:['Not abstracting away narrative details before coding, leading to overcomplicated logic','Missing edge cases implied by the story but not explicitly stated as constraints'],
 skip:'Skip only if severely time-constrained (under 10 minutes remaining) since this is the lowest-hit-rate, highest-effort question — attempt only after c2p1 is fully secured.',
 time:'15-25 min',
 quiz:[{q:'Best first step for a long story-based coding problem?',opts:['Start coding immediately based on the story','Strip the narrative and extract inputs/constraints/output first','Ignore the problem if it seems complex','Copy a similar-sounding template without reading fully'],ans:1,exp:'Extracting the underlying algorithmic structure before coding avoids wasted effort building overcomplicated narrative-literal logic.'}]},
{id:'c3p2', topicId:'c3', name:'Rule-Based String Conversion Pattern', freq:4, imp:'high',
 why:'Tests systematic application of a stated transformation rule across every character/position of a string — a discipline and edge-case-handling check dressed as a "convert A to B" narrative.',
 rec:'A stated rule converts string A to string B character-by-character (or position-by-position) based on a condition → apply the rule mechanically to every position, and simulate the FULL described process (including any repetition/iteration count) rather than solving only the first step.',
 tree:['Extract the exact conversion rule stated (e.g. shift character forward/backward under some condition)','Determine if the rule is applied once, or repeatedly until a target condition is met','Apply the rule position-by-position (or iteration-by-iteration) exactly as specified','Verify against any given worked example before generalizing to the full input'],
 example:'Ayush converts string A to B (equal length N, lowercase) based on specific rules — commonly: for each position, compute an operation (e.g. difference in alphabet position) and either apply it directly or repeat the process to count steps/iterations required, matching the exact rule as stated in the problem.',
 variations:['Rule applied once per character (single-pass transformation)','Rule applied repeatedly (count iterations until string A equals string B)','Rule involves wraparound (e.g. after \'z\' comes \'a\' again) requiring modulus arithmetic on alphabet positions'],
 related:'c3p1, c1p2',
 trap:'Applying the rule only once when the problem actually requires repeated application until a target state is reached — always check whether the problem asks for a "number of steps" or the "final resulting string".',
 difficulty:'Hard', mistakes:['Not handling alphabet wraparound (z→a) with proper modulus arithmetic','Confusing "single transformation" output with a "repeat until condition met" iteration-count output'],
 skip:'Skip only after securing c2p1 (guaranteed easier hands-on question) if time is limited.',
 time:'15-20 min',
 quiz:[{q:'When a string-conversion rule wraps around the alphabet (z→a), the correct technique is:',opts:['Simple addition without bounds','Modulus arithmetic on alphabet positions (mod 26)','Ignore wraparound cases','Convert to uppercase first'],ans:1,exp:'Modulus 26 arithmetic correctly handles alphabet wraparound in position-shift rules.'}]},
];

// build lookup maps
const TOPIC_BY_ID = {}; TOPICS.forEach(t=>TOPIC_BY_ID[t.id]=t);
const PATTERN_BY_ID = {}; PATTERNS.forEach(p=>PATTERN_BY_ID[p.id]=p);
TOPICS.forEach(t=>{ t.patterns = PATTERNS.filter(p=>p.topicId===t.id).sort((a,b)=>b.freq-a.freq); });

// ---- 15 day plan: teach by pattern priority, not by topic, across all sections ----
const ALL_PATTERNS_SORTED = [...PATTERNS].sort((a,b)=> b.freq - a.freq);
const TEACH_DAYS = 12;
function buildStudyDays(){
  const days = [];
  const perDay = Math.ceil(ALL_PATTERNS_SORTED.length / TEACH_DAYS);
  for(let d=0; d<TEACH_DAYS; d++){
    const slice = ALL_PATTERNS_SORTED.slice(d*perDay,(d+1)*perDay);
    days.push({day:d+1, phase:'LEARN', patterns:slice.map(p=>p.id)});
  }
  // last 3 days
  days.push({day:13, phase:'REVISE + MOCK 1', patterns:[], note:'Full pattern revision pass (Day 1-6 patterns) + one mixed mock covering Quant & Reasoning.'});
  days.push({day:14, phase:'MOCK 2 + WEAK-TOPIC DRILL', patterns:[], note:'Full mixed mock (all 4 sections) + targeted drill on your Weak Topics from the Dashboard.'});
  days.push({day:15, phase:'FINAL REVISION + CONFIDENCE', patterns:[], note:'Rapid-fire revision of every P0 pattern checklist + light mock to close on a confidence high, not new material.'});
  return days;
}
const STUDY_DAYS = buildStudyDays();

/* ============================================================
   STORAGE HELPERS  (persisted via window.storage, personal/non-shared)
   ============================================================ */
const CHECK_KEYS = ['understood','solvedExamples','solvedPYQs','revision1','revision2','mastered'];
const CHECK_LABELS = {understood:'Understood', solvedExamples:'Solved Examples', solvedPYQs:'Solved PYQs', revision1:'Revision 1', revision2:'Revision 2', mastered:'Mastered'};

let PROGRESS = {}; // patternId -> {checklist:{}, quizBest:n, quizTotal:n}
let PREFS = {theme:'dark', startDate: null};

async function loadAll(){
  try{
    const list = await window.storage.list('progress:', false);
    if(list && list.keys){
      for(const k of list.keys){
        try{
          const r = await window.storage.get(k, false);
          if(r) PROGRESS[k.replace('progress:','')] = JSON.parse(r.value);
        }catch(e){}
      }
    }
  }catch(e){ console.warn('progress list failed', e); }
  try{
    const p = await window.storage.get('prefs', false);
    if(p) PREFS = Object.assign(PREFS, JSON.parse(p.value));
  }catch(e){ /* no prefs yet */ }
  if(!PREFS.startDate){ PREFS.startDate = new Date().toISOString().slice(0,10); await savePrefs(); }
}
async function savePrefs(){ try{ await window.storage.set('prefs', JSON.stringify(PREFS), false); }catch(e){} }
async function saveProgress(patternId){
  try{ await window.storage.set('progress:'+patternId, JSON.stringify(PROGRESS[patternId]||{}), false); }catch(e){}
}
function getProg(patternId){
  if(!PROGRESS[patternId]) PROGRESS[patternId] = {checklist:{}, quizBest:0, quizTotal:0};
  if(!PROGRESS[patternId].checklist) PROGRESS[patternId].checklist = {};
  return PROGRESS[patternId];
}
function confidenceScore(patternId){
  const prog = getProg(patternId);
  const done = CHECK_KEYS.filter(k=>prog.checklist[k]).length;
  return Math.round((done/CHECK_KEYS.length)*100);
}
function topicCompletion(topicId){
  const t = TOPIC_BY_ID[topicId];
  if(!t || !t.patterns.length) return 0;
  const sum = t.patterns.reduce((s,p)=>s+confidenceScore(p.id),0);
  return Math.round(sum/t.patterns.length);
}
function sectionCompletion(sectionId){
  const ts = TOPICS.filter(t=>t.section===sectionId);
  if(!ts.length) return 0;
  return Math.round(ts.reduce((s,t)=>s+topicCompletion(t.id),0)/ts.length);
}
function overallCompletion(){
  if(!TOPICS.length) return 0;
  return Math.round(TOPICS.reduce((s,t)=>s+topicCompletion(t.id),0)/TOPICS.length);
}
function daysSinceStart(){
  const start = new Date(PREFS.startDate);
  const now = new Date();
  const diff = Math.floor((now - start)/(1000*60*60*24));
  return Math.max(0, Math.min(15, diff));
}

/* ============================================================
   ROUTER
   ============================================================ */
function currentRoute(){
  const h = location.hash.replace('#/','') || 'dashboard';
  return h.split('/');
}
window.addEventListener('hashchange', render);

/* ============================================================
   SMALL RENDER HELPERS
   ============================================================ */
function esc(s){ return (s||'').toString().replace(/[&<>"']/g, c=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c])); }
function impBadge(imp){
  const map = {strict:['strict','Strictly On-Campus'], high:['high','Highly On-Campus'], common:['common','Common On-Campus']};
  const [cls,label] = map[imp]||['common','Common'];
  return `<span class="badge ${cls}">${label}</span>`;
}
function prioBadge(p){
  const cls = p==='P0'?'p0':(p==='P1'?'p1':'p2');
  return `<span class="badge ${cls}">${p}</span>`;
}
function freqMeter(freq){
  let dots='';
  for(let i=1;i<=5;i++) dots += `<span class="fd ${i<=freq?'on':''}"></span>`;
  return `<span class="freq-meter">${dots}</span>`;
}
function sectionPill(sectionId){
  const s = SECTIONS.find(x=>x.id===sectionId);
  return `<span class="section-pill ${s.pill}">${s.name}</span>`;
}
function go(hash){ location.hash = '#/'+hash; }

/* ============================================================
   VIEWS
   ============================================================ */
function viewDashboard(){
  const overall = overallCompletion();
  const dayIdx = daysSinceStart();
  let runway = '';
  for(let i=1;i<=15;i++){
    let cls = i < dayIdx+1 ? 'done' : (i===dayIdx+1?'today':'');
    runway += `<div class="seg ${cls}">D${i}</div>`;
  }
  // weak/strong topics by completion
  const ranked = TOPICS.map(t=>({t, c:topicCompletion(t.id)})).sort((a,b)=>a.c-b.c);
  const weak = ranked.slice(0,3);
  const strong = [...ranked].sort((a,b)=>b.c-a.c).slice(0,3);
  const p0Count = PATTERNS.filter(p=>p.freq===5).length;

  return `
  <div class="eyebrow">◆ Mission Control</div>
  <h1 class="pagetitle">Your TCS On-Campus Readiness</h1>
  <p class="pagesub">Everything here is scoped to what TCS actually tests on-campus — no off-campus filler. Track pattern mastery, not topic theory.</p>

  <div class="stat-row">
    <div class="stat-card"><div class="num">${overall}%</div><div class="lbl">Overall pattern mastery</div></div>
    <div class="stat-card"><div class="num">${PATTERNS.length}</div><div class="lbl">Total patterns tracked</div></div>
    <div class="stat-card"><div class="num">${p0Count}</div><div class="lbl">Strictly on-campus (5★) patterns</div></div>
    <div class="stat-card"><div class="num">${Math.min(dayIdx+1,15)}/15</div><div class="lbl">Day of your prep runway</div></div>
  </div>

  <div class="card" style="margin-bottom:22px;">
    <div class="block-title">15-Day Runway</div>
    <p style="color:var(--muted); font-size:12.5px; margin:0 0 4px;">Day 1 = the day you opened this portal. Click a day in the Plan for what to teach yourself today.</p>
    <div class="runway-big">${runway}</div>
    <div style="margin-top:12px;"><a class="btn primary" href="#/plan">Open today's plan →</a></div>
  </div>

  <div class="grid g2" style="margin-bottom:8px;">
    <div class="card">
      <div class="block-title" style="color:var(--danger);">Weak Topics</div>
      ${weak.map(w=>`<div class="topic-row"><a href="#/topic/${w.t.id}" style="flex:1; display:flex; align-items:center; gap:12px;"><span class="name">${esc(w.t.name)}</span></a><div class="mini-bar"><i style="width:${w.c}%; background:var(--danger);"></i></div><span style="font-family:var(--font-mono); font-size:11.5px; color:var(--muted); width:34px; text-align:right;">${w.c}%</span></div>`).join('')}
    </div>
    <div class="card">
      <div class="block-title" style="color:var(--accent2);">Strong Topics</div>
      ${strong.map(w=>`<div class="topic-row"><a href="#/topic/${w.t.id}" style="flex:1; display:flex; align-items:center; gap:12px;"><span class="name">${esc(w.t.name)}</span></a><div class="mini-bar"><i style="width:${w.c}%;"></i></div><span style="font-family:var(--font-mono); font-size:11.5px; color:var(--muted); width:34px; text-align:right;">${w.c}%</span></div>`).join('')}
    </div>
  </div>

  <hr class="rule">
  <div class="block-title">Sections</div>
  <div class="grid g4">
    ${SECTIONS.map(s=>{
      const sc = sectionCompletion(s.id);
      return `<a class="card" href="#/section/${s.id}">
        <div class="section-pill ${s.pill}" style="margin-bottom:10px;">${s.name}</div>
        <div style="font-family:var(--font-display); font-size:22px; font-weight:700;">${sc}%</div>
        <div class="progress-bar" style="margin-top:8px;"><i style="width:${sc}%"></i></div>
        <div style="font-size:11.5px; color:var(--muted); margin-top:8px;">${TOPICS.filter(t=>t.section===s.id).length} topics</div>
      </a>`;
    }).join('')}
  </div>
  `;
}

function viewSection(sectionId){
  const s = SECTIONS.find(x=>x.id===sectionId);
  if(!s) return `<div class="empty">Section not found.</div>`;
  const topics = TOPICS.filter(t=>t.section===sectionId);
  return `
  <div class="eyebrow">${s.pill?`<span class="section-pill ${s.pill}">${s.name}</span>`:''}</div>
  <h1 class="pagetitle">${s.name}</h1>
  <p class="pagesub">Topics below are ordered by on-campus priority. Every topic opens its own pattern database — study by pattern, not theory.</p>
  <div class="filterbar">
    <select id="priorityFilter"><option value="">All priorities</option><option value="P0">P0 — Must clear</option><option value="P1">P1 — High value</option><option value="P2">P2 — Nice to have</option></select>
  </div>
  <div id="topicList">
    ${topics.map(topicCardHtml).join('')}
  </div>
  `;
}
function topicCardHtml(t){
  const comp = topicCompletion(t.id);
  return `<a class="topic-card" data-prio="${t.priority}" href="#/topic/${t.id}">
    <div class="row1">
      ${prioBadge(t.priority)}
      <span class="tname">${esc(t.name)}</span>
    </div>
    <div class="meta-strip">
      <span>Est. Qs: <b>${t.estQ}</b></span>
      <span>Difficulty: <b>${t.difficulty}</b></span>
      <span>Study time: <b>${t.studyTime}</b></span>
      <span>Patterns: <b>${t.patterns.length}</b></span>
      <span>Mastery: <b>${comp}%</b></span>
    </div>
    <div class="progress-bar" style="margin-top:10px;"><i style="width:${comp}%"></i></div>
  </a>`;
}

function viewTopic(topicId){
  const t = TOPIC_BY_ID[topicId];
  if(!t) return `<div class="empty">Topic not found.</div>`;
  const comp = topicCompletion(t.id);
  const patterns = t.patterns;
  // prev/next topic within same section, by array order
  const sectionTopics = TOPICS.filter(x=>x.section===t.section);
  const idx = sectionTopics.findIndex(x=>x.id===t.id);
  const prevT = sectionTopics[idx-1];
  const nextT = sectionTopics[idx+1];
  const related = (t.related||[]).map(id=>TOPIC_BY_ID[id]).filter(Boolean);
  // revision due: any pattern with understood+solvedExamples done but revision2 not done
  const dueList = patterns.filter(p=>{
    const c = getProg(p.id).checklist;
    return c.understood && c.solvedPYQs && !c.revision2;
  });

  return `
  <div class="eyebrow">${sectionPill(t.section)}</div>
  <h1 class="pagetitle">${esc(t.name)}</h1>
  <p class="pagesub">${esc(t.importance)}</p>

  <div class="meta-grid">
    <div class="cell"><div class="k">Priority</div><div class="v">${t.priority}</div></div>
    <div class="cell"><div class="k">Est. Questions</div><div class="v">${t.estQ}</div></div>
    <div class="cell"><div class="k">Difficulty</div><div class="v">${t.difficulty}</div></div>
    <div class="cell"><div class="k">Study Time</div><div class="v">${t.studyTime}</div></div>
    <div class="cell"><div class="k">Mastery</div><div class="v">${comp}%</div></div>
    <div class="cell"><div class="k">Patterns</div><div class="v">${patterns.length}</div></div>
  </div>

  <div class="block-title">Question Pattern Database <span style="font-family:var(--font-mono); font-size:11px; color:var(--muted2); font-weight:400; margin-left:6px;">(highest frequency first)</span></div>
  ${patterns.map((p,i)=>{
    const conf = confidenceScore(p.id);
    return `<a class="pattern-row" href="#/pattern/${p.id}">
      <div class="prow-top">
        <span class="prow-rank">#${i+1}</span>
        <span class="prow-name">${esc(p.name)}</span>
        ${freqMeter(p.freq)}
        ${impBadge(p.imp)}
        <span class="prow-check">${conf}%</span>
      </div>
      <div style="font-size:12.5px; color:var(--muted); padding-left:32px;">${esc(p.why.slice(0,140))}${p.why.length>140?'…':''}</div>
    </a>`;
  }).join('') || '<div class="empty">No patterns yet.</div>'}

  <hr class="rule">
  <div class="bottom-nav">
    <div class="nav-card"><div class="k">Related Topics</div>
      ${related.length? `<div class="chip-row">${related.map(r=>`<a class="chip" href="#/topic/${r.id}">${esc(r.name.split('(')[0].trim())}</a>`).join('')}</div>` : '<span style="color:var(--muted); font-size:12.5px;">None linked.</span>'}
    </div>
    <div class="nav-card"><div class="k">Revision Due</div>
      ${dueList.length? `<div class="chip-row">${dueList.map(p=>`<a class="chip" href="#/pattern/${p.id}">${esc(p.name)}</a>`).join('')}</div>` : '<span style="color:var(--muted); font-size:12.5px;">Nothing due — keep going!</span>'}
    </div>
    <div class="nav-card"><div class="k">Previous Topic</div>
      ${prevT? `<a class="chip" href="#/topic/${prevT.id}">← ${esc(prevT.name.split('(')[0].trim())}</a>` : '<span style="color:var(--muted); font-size:12.5px;">Start of section.</span>'}
    </div>
    <div class="nav-card"><div class="k">Next Recommended Topic</div>
      ${nextT? `<a class="chip" href="#/topic/${nextT.id}">${esc(nextT.name.split('(')[0].trim())} →</a>` : '<span style="color:var(--muted); font-size:12.5px;">Section complete!</span>'}
    </div>
  </div>
  `;
}

function ringGradient(pct){
  const color = pct>=70?'var(--accent2)':(pct>=35?'var(--accent)':'var(--danger)');
  return `background:conic-gradient(${color} ${pct*3.6}deg, var(--surface3) 0deg); `;
}

function viewPattern(patternId){
  const p = PATTERN_BY_ID[patternId];
  if(!p) return `<div class="empty">Pattern not found.</div>`;
  const t = TOPIC_BY_ID[p.topicId];
  const prog = getProg(p.id);
  const conf = confidenceScore(p.id);
  const sameTopicPatterns = t.patterns;
  const idx = sameTopicPatterns.findIndex(x=>x.id===p.id);
  const prevP = sameTopicPatterns[idx-1];
  const nextP = sameTopicPatterns[idx+1];
  // next recommended across ALL patterns by frequency, not yet mastered
  const nextRecommended = ALL_PATTERNS_SORTED.find(x=>x.id!==p.id && confidenceScore(x.id) < 100 && x.freq <= p.freq) || ALL_PATTERNS_SORTED.find(x=>x.id!==p.id);

  return `
  <div class="eyebrow"><a href="#/topic/${t.id}" style="color:var(--accent);">${sectionPill(t.section)}</a> &nbsp;/&nbsp; <a href="#/topic/${t.id}">${esc(t.name.split('(')[0].trim())}</a></div>
  <div class="p-hero">
    <div class="htop">
      ${freqMeter(p.freq)} ${impBadge(p.imp)}
      <span style="flex:1;"></span>
      <div class="confidence-ring" style="${ringGradient(conf)}" title="Confidence score">
        <div style="width:50px;height:50px;border-radius:50%;background:var(--surface);display:flex;align-items:center;justify-content:center;">
          <span class="cnum">${conf}%</span>
        </div>
      </div>
    </div>
    <h1>${esc(p.name)}</h1>
    <div style="font-size:13px; color:var(--muted); display:flex; gap:18px; flex-wrap:wrap; font-family:var(--font-mono); margin-top:6px;">
      <span>Difficulty: <b style="color:var(--text);">${p.difficulty}</b></span>
      <span>Time target: <b style="color:var(--text);">${p.time}</b></span>
    </div>
  </div>

  <div class="two-col">
    <div>
      <div class="block-title">Why TCS Asks This</div>
      <p style="font-size:13.5px; line-height:1.6; color:var(--text); margin:0 0 20px;">${esc(p.why)}</p>

      <div class="block-title">Pattern Recognition — spot it in 10 seconds</div>
      <p style="font-size:13.5px; line-height:1.6; margin:0 0 12px;">${esc(p.rec)}</p>
      <div class="tree">
        ${p.tree.map((step,i)=>`<div class="tree-step"><div class="tree-num">${i+1}</div><div class="tree-txt">${esc(step)}</div></div>`).join('')}
      </div>

      <div class="block-title" style="margin-top:22px;">Representative Example</div>
      <div class="example-box">${esc(p.example)}</div>

      <div class="block-title">3 Variations of This Pattern</div>
      ${p.variations.map((v,i)=>`<div class="var-box"><b>Variation ${i+1}</b>${esc(v)}</div>`).join('')}

      <div class="block-title" style="margin-top:22px;">Typical Mistakes</div>
      ${p.mistakes.map(m=>`<div class="mistake-item">⚠ ${esc(m)}</div>`).join('')}
      <div class="block-title" style="margin-top:18px;">Common Trap</div>
      <div class="trap-box">🎯 ${esc(p.trap)}</div>

      <div class="grid g2" style="margin-top:18px;">
        <div class="card" style="padding:14px 16px;"><div class="k" style="font-family:var(--font-mono); font-size:10.5px; color:var(--muted2); text-transform:uppercase; margin-bottom:6px;">When to Skip</div><div style="font-size:13px;">${esc(p.skip)}</div></div>
        <div class="card" style="padding:14px 16px;"><div class="k" style="font-family:var(--font-mono); font-size:10.5px; color:var(--muted2); text-transform:uppercase; margin-bottom:6px;">Related Pattern</div><div style="font-size:13px;">${esc(p.related)}</div></div>
      </div>

      <div class="block-title" style="margin-top:22px;">Mini Quiz</div>
      <div id="quizArea">${p.quiz.map((q,qi)=>quizHtml(p.id,qi,q)).join('')}</div>
    </div>

    <div>
      <div class="card" style="margin-bottom:16px;">
        <div class="block-title">Pattern Progress</div>
        <div class="checklist" id="checklistArea">
          ${CHECK_KEYS.map(k=>`
            <label class="check-item ${prog.checklist[k]?'done':''}" data-key="${k}">
              <input type="checkbox" ${prog.checklist[k]?'checked':''} data-check="${k}">
              <span>${CHECK_LABELS[k]}</span>
            </label>`).join('')}
        </div>
      </div>
      <div class="card" style="margin-bottom:16px;">
        <div class="block-title">Revision Status</div>
        <p style="font-size:13px; color:var(--muted); margin:0;">${revisionStatusText(prog)}</p>
      </div>
      <div class="card">
        <div class="block-title">Confidence Score</div>
        <div class="progress-bar" style="margin-bottom:8px;"><i style="width:${conf}%"></i></div>
        <p style="font-size:12.5px; color:var(--muted); margin:0;">Auto-computed from your checklist (${CHECK_KEYS.filter(k=>prog.checklist[k]).length}/${CHECK_KEYS.length} steps done). Best quiz score: ${prog.quizBest||0}/${p.quiz.length}.</p>
      </div>
    </div>
  </div>

  <hr class="rule">
  <div class="bottom-nav" style="grid-template-columns:repeat(4,1fr);">
    <div class="nav-card"><div class="k">Related Topics</div><a class="chip" href="#/topic/${t.id}">${esc(t.name.split('(')[0].trim())}</a></div>
    <div class="nav-card"><div class="k">Next Recommended Pattern</div>${nextRecommended?`<a class="chip" href="#/pattern/${nextRecommended.id}">${esc(nextRecommended.name)} →</a>`:'<span style="color:var(--muted); font-size:12.5px;">All caught up!</span>'}</div>
    <div class="nav-card"><div class="k">Previous Pattern (this topic)</div>${prevP?`<a class="chip" href="#/pattern/${prevP.id}">← ${esc(prevP.name)}</a>`:'<span style="color:var(--muted); font-size:12.5px;">First in topic.</span>'}</div>
    <div class="nav-card"><div class="k">Revision Due</div>${(!prog.checklist.revision2 && prog.checklist.mastered)?`<span class="chip" style="border-color:var(--accent); color:var(--accent);">Due for Revision 2</span>`:'<span style="color:var(--muted); font-size:12.5px;">Not due yet.</span>'}</div>
  </div>
  `;
}
function revisionStatusText(prog){
  const c = prog.checklist;
  if(c.mastered && c.revision2) return "Fully mastered and revised twice. Revisit only in final 3-day mock phase.";
  if(c.mastered && !c.revision2) return "Marked mastered — schedule Revision 2 before Day 13.";
  if(c.revision1) return "Revision 1 done — attempt Revision 2 and Mastered once confident.";
  if(c.solvedPYQs) return "PYQs solved — do a revision pass next.";
  if(c.solvedExamples) return "Examples solved — attempt real PYQs next.";
  if(c.understood) return "Understood — now solve the examples above.";
  return "Not started. Read Pattern Recognition + Example, then check Understood.";
}
function quizHtml(patternId, qi, q){
  return `<div class="quiz-q" data-pattern="${patternId}" data-qi="${qi}">
    <div class="qtext">Q${qi+1}. ${esc(q.q)}</div>
    ${q.opts.map((o,oi)=>`<button class="quiz-opt" data-oi="${oi}">${esc(o)}</button>`).join('')}
    <div class="quiz-exp" style="display:none;"></div>
  </div>`;
}

function viewPlan(){
  const dayIdx = daysSinceStart()+1;
  const activeParam = currentRoute()[1];
  const activeDay = activeParam ? parseInt(activeParam) : Math.min(dayIdx,15);
  return `
  <div class="eyebrow">◆ 15-Day Preparation Engine</div>
  <h1 class="pagetitle">Pattern-Priority Study Plan</h1>
  <p class="pagesub">You teach yourself by <b>pattern ROI</b>, not by topic. Days 1-12 walk through every pattern in decreasing on-campus frequency across all four sections. Days 13-15 are pure revision, mocks, and confidence-building.</p>
  <div class="day-tabs">
    ${STUDY_DAYS.map(d=>{
      const complete = d.patterns.length && d.patterns.every(pid=>getProg(pid).checklist.mastered);
      return `<a class="day-tab ${d.day===activeDay?'active':''} ${complete?'complete':''}" href="#/plan/${d.day}">Day ${d.day}</a>`;
    }).join('')}
  </div>
  <div id="dayContent">${dayContentHtml(activeDay)}</div>
  `;
}
function dayContentHtml(day){
  const d = STUDY_DAYS.find(x=>x.day===day);
  if(!d) return '<div class="empty">Pick a day above.</div>';
  if(d.patterns.length===0){
    return `<div class="card"><div class="day-phase">${esc(d.phase)}</div><p style="font-size:14px; line-height:1.6;">${esc(d.note)}</p>
    <div class="tag-row"><a class="btn primary" href="#/dashboard">Check weak topics on Dashboard →</a></div></div>`;
  }
  return `<div class="day-phase">${esc(d.phase)} · ${d.patterns.length} pattern(s)</div>
  ${d.patterns.map((pid,i)=>{
    const p = PATTERN_BY_ID[pid]; const t = TOPIC_BY_ID[p.topicId]; const conf = confidenceScore(pid);
    const locked = i>0 ? !getProg(d.patterns[i-1]).checklist.understood : false;
    return `<a class="plan-item" href="#/pattern/${p.id}" style="${locked?'opacity:.55;':''}">
      <span class="pidx">${String(i+1).padStart(2,'0')}</span>
      ${sectionPill(t.section)}
      ${freqMeter(p.freq)}
      <span class="ptitle">${esc(p.name)}</span>
      <span class="ptime">${p.time}</span>
      <span style="font-family:var(--font-mono); font-size:11.5px; color:var(--accent2);">${conf}%</span>
    </a>`;
  }).join('')}
  `;
}

function viewSearch(query){
  const q = query.toLowerCase();
  const patternHits = PATTERNS.filter(p=>p.name.toLowerCase().includes(q) || p.why.toLowerCase().includes(q));
  const topicHits = TOPICS.filter(t=>t.name.toLowerCase().includes(q));
  return `
  <div class="eyebrow">◆ Search</div>
  <h1 class="pagetitle">Results for "${esc(query)}"</h1>
  <div class="block-title">Topics (${topicHits.length})</div>
  ${topicHits.map(topicCardHtml).join('') || '<p style="color:var(--muted);">No topic matches.</p>'}
  <div class="block-title" style="margin-top:22px;">Patterns (${patternHits.length})</div>
  ${patternHits.map(p=>{
    const t = TOPIC_BY_ID[p.topicId];
    return `<a class="pattern-row" href="#/pattern/${p.id}"><div class="prow-top"><span class="prow-name">${esc(p.name)}</span>${freqMeter(p.freq)}${impBadge(p.imp)}</div><div style="font-size:12px; color:var(--muted); padding-left:2px;">${sectionPill(t.section)} · ${esc(t.name.split('(')[0].trim())}</div></a>`;
  }).join('') || '<p style="color:var(--muted);">No pattern matches.</p>'}
  `;
}

/* ============================================================
   MAIN RENDER
   ============================================================ */
function render(){
  const route = currentRoute();
  const content = document.getElementById('content');
  let html = '';
  if(route[0]==='dashboard' || route[0]===''){ html = viewDashboard(); }
  else if(route[0]==='section'){ html = viewSection(route[1]); }
  else if(route[0]==='topic'){ html = viewTopic(route[1]); }
  else if(route[0]==='pattern'){ html = viewPattern(route[1]); }
  else if(route[0]==='plan'){ html = viewPlan(); }
  else if(route[0]==='search'){ html = viewSearch(decodeURIComponent(route[1]||'')); }
  else { html = '<div class="empty">Page not found.</div>'; }
  content.innerHTML = html;
  window.scrollTo(0,0);
  bindContentEvents(route);
  buildNav(route);
  buildMiniRunway();
  closeSidebarMobile();
}

function bindContentEvents(route){
  // priority filter on section page
  const pf = document.getElementById('priorityFilter');
  if(pf){
    pf.addEventListener('change', ()=>{
      const v = pf.value;
      document.querySelectorAll('#topicList .topic-card').forEach(el=>{
        el.style.display = (!v || el.dataset.prio===v) ? '' : 'none';
      });
    });
  }
  // checklist toggles on pattern page
  document.querySelectorAll('[data-check]').forEach(inp=>{
    inp.addEventListener('change', async (e)=>{
      const pid = route[1];
      const key = e.target.dataset.check;
      const prog = getProg(pid);
      prog.checklist[key] = e.target.checked;
      await saveProgress(pid);
      render(); // refresh confidence, badges, nav states
      location.hash = '#/pattern/'+pid;
    });
  });
  // quiz interactions
  document.querySelectorAll('.quiz-q').forEach(qEl=>{
    const patternId = qEl.dataset.pattern; const qi = parseInt(qEl.dataset.qi);
    const p = PATTERN_BY_ID[patternId]; const q = p.quiz[qi];
    qEl.querySelectorAll('.quiz-opt').forEach(btn=>{
      btn.addEventListener('click', async ()=>{
        if(qEl.dataset.answered) return;
        qEl.dataset.answered = '1';
        const oi = parseInt(btn.dataset.oi);
        qEl.querySelectorAll('.quiz-opt').forEach((b,i)=>{
          if(i===q.ans) b.classList.add('correct');
          else if(i===oi) b.classList.add('wrong');
        });
        const expEl = qEl.querySelector('.quiz-exp');
        expEl.style.display = 'block';
        expEl.textContent = (oi===q.ans? '✓ Correct. ':'✗ Not quite. ') + q.exp;
        if(oi===q.ans){
          const prog = getProg(patternId);
          prog.quizBest = Math.min((prog.quizBest||0)+0, p.quiz.length); // placeholder, recompute below
          const correctCount = [...qEl.parentElement.querySelectorAll('.quiz-q')].filter(el=>el.querySelector('.quiz-opt.correct')).length;
          prog.quizBest = Math.max(prog.quizBest||0, correctCount);
          prog.quizTotal = p.quiz.length;
          await saveProgress(patternId);
        }
      });
    });
  });
}

/* ---------- nav + search + theme ---------- */
function buildNav(route){
  const nav = document.getElementById('navlinks');
  const links = [{id:'dashboard', label:'Dashboard', hash:'dashboard'}]
    .concat(SECTIONS.map(s=>({id:'section-'+s.id, label:s.name, hash:'section/'+s.id})))
    .concat([{id:'plan', label:'15-Day Plan', hash:'plan'}]);
  nav.innerHTML = links.map(l=>{
    const active = (route[0]==='dashboard'&&l.id==='dashboard') || (route[0]==='section'&&l.hash==='section/'+route[1]) || (route[0]==='plan'&&l.id==='plan');
    return `<a class="navlink ${active?'active':''}" href="#/${l.hash}"><span class="dot"></span>${l.label}</a>`;
  }).join('');
}
function buildMiniRunway(){
  const el = document.getElementById('miniRunway');
  const dayIdx = daysSinceStart();
  let html='';
  for(let i=1;i<=15;i++){
    const cls = i<dayIdx+1?'done':(i===dayIdx+1?'today':'');
    html += `<div class="runway-seg ${cls}"></div>`;
  }
  el.innerHTML = html;
}

const searchInput = document.getElementById('searchInput');
const searchResults = document.getElementById('searchResults');
searchInput.addEventListener('input', ()=>{
  const q = searchInput.value.trim().toLowerCase();
  if(!q){ searchResults.style.display='none'; return; }
  const patternHits = PATTERNS.filter(p=>p.name.toLowerCase().includes(q)).slice(0,6);
  const topicHits = TOPICS.filter(t=>t.name.toLowerCase().includes(q)).slice(0,4);
  if(!patternHits.length && !topicHits.length){ searchResults.style.display='none'; return; }
  searchResults.innerHTML = [
    ...topicHits.map(t=>`<a class="sr-item" href="#/topic/${t.id}"><span class="sr-tag">Topic</span>${esc(t.name)}</a>`),
    ...patternHits.map(p=>`<a class="sr-item" href="#/pattern/${p.id}"><span class="sr-tag">Pattern</span>${esc(p.name)}</a>`)
  ].join('');
  searchResults.style.display='block';
});
searchInput.addEventListener('keydown', (e)=>{
  if(e.key==='Enter' && searchInput.value.trim()){
    go('search/'+encodeURIComponent(searchInput.value.trim()));
    searchResults.style.display='none';
  }
});
document.addEventListener('click', (e)=>{
  if(!e.target.closest('.searchwrap')) searchResults.style.display='none';
});

const themeToggle = document.getElementById('themeToggle');
themeToggle.addEventListener('click', async ()=>{
  const isLight = document.documentElement.classList.toggle('light');
  PREFS.theme = isLight ? 'light' : 'dark';
  await savePrefs();
});

const hamburger = document.getElementById('hamburger');
const sidebar = document.getElementById('sidebar');
const overlay = document.getElementById('overlay');
hamburger.addEventListener('click', ()=>{ sidebar.classList.add('open'); overlay.classList.add('show'); });
overlay.addEventListener('click', ()=>{ sidebar.classList.remove('open'); overlay.classList.remove('show'); });
function closeSidebarMobile(){ sidebar.classList.remove('open'); overlay.classList.remove('show'); }

/* ============================================================
   INIT
   ============================================================ */
(async function init(){
  await loadAll();
  if(PREFS.theme==='light') document.documentElement.classList.add('light');
  render();
})();
</script>
</body>
</html>

You have already created the TCS On-Campus Pattern Portal.
Now transform it into a Pattern Intelligence System.
Do NOT add more theory.
Instead build features that maximize my probability of clearing TCS On-Campus.
For every pattern create:
1. Pattern Dependency Graph
2. Similar Pattern Detection
3. Pattern Recognition Quiz
4. Memory-Based TCS Questions
5. TCS Pattern Variations
6. AI Generated Similar Questions
7. Revision Scheduler
8. Weak Pattern Detection
9. Confidence Score
10. Pattern Heatmap
11. Pattern Completion %
12. Estimated Exam Probability
13. Recommended Next Pattern
14. Pattern Revision Calendar
15. Mock Generator using only previously observed TCS On-Campus patterns.
The website should behave like LeetCode + Notion + Anki + Roadmap.sh + Duolingo, but optimized exclusively for TCS On-Campus preparation.
Every feature must reduce study time and increase pattern recognition.
The objective is not syllabus completion.
The objective is maximum probability of clearing TCS On-Campus in minimum time.
