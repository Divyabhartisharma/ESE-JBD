from pycpa import model
from pycpa import analysis
from pycpa import schedulers
from pycpa import graph
from pycpa import options
from pycpa import simulation
from pycpa import *
from pycpa import model, analysis, plot
from matplotlib import pyplot


##generate an new system
options.init_pycpa()

s = model.System()

##now define the resources
r1 = s.bind_resource(model.Resource("Resource1", schedulers.SPPScheduler()))
#r2 = s.bind_resource(model.Resource("Resource2", schedulers.SPPScheduler()))

##create and bind Jobs to resource1
J11 = r1.bind_task(model.Task("JFirstJob in priority J11", wcet=1,  bcet=0.5, scheduling_parameter=1))
J12 = r1.bind_task(model.Task("Jsecond in priority J12", wcet=1.83,  bcet=0.5,scheduling_parameter=2))
#create and bind jobs to resource2
# J21 = r2.bind_task(model.Task("JFirst in priority J21 ", wcet=1,  bcet=0.5, scheduling_parameter=3))
# J22 = r2.bind_task(model.Task("JSecond in priority J22", wcet=1.83,  bcet=1,scheduling_parameter=4))

# specify precedence constraints: J11 -> J21; J12-> J22
J11.link_dependent_task(J12)
# J12.link_dependent_task(J22)

# register a periodic with jitter event model for J11 and J12
#here P is the period , jitter -computation gap
J11.in_event_model = model.PJdEventModel(P=10, J=5)
J12.in_event_model = model.PJdEventModel(P=20, J=6)

# plot the system graph to visualize the architecture
g = graph.graph_system(s, filename='Tasks.pdf',dotout='Tasks.dot')

# perform the analysis
print("Performing analysis")
Plot_job = [J11,J12]
task_results = analysis.analyze_system(s)
# print the worst case response times (WCRTs)
sim = simulation.SimTask('q',J11)


print("Result:")
for r in sorted(s.resources, key=str):
    for t in sorted(r.tasks, key=str):
        print("%s: wcrt=%d" % (t.name, task_results[t].wcrt))
        print(" b_wcrt=%s" % (task_results[t].b_wcrt_str()))

for e in Plot_job:
    plot.plot_event_model(e.in_event_model, 4, separate_plots=False, file_format='pdf',
    file_prefix='event-model-%s'% e.name, ticks_at_steps=False)


# plot_in=[t1,t2]
# for t in plot_in:
#     s = plot.plot_gantt(plot_in, task_results, file_name = 'f.PDF', show = False,
#                             xlim = None, preemtion_bar_height = 0.2, height = 1, hdist = 1,
#                             bar_linewidth = 1, min_dist_arrows = 0.2, plot_event_arrival = True,
#                             plot_activation_finishing = False, annotate_tasks = True, task = t1,
#                             wcrt_voffset = 0.5, annotation_offset = 0.2, arrow_width = 0.05,
#                             arrow_head_width = 0.4, arrow_head_length = 0.2, arrow_xscale = 1, arrow_yoffset = 0.1, xticks_only_on_changes = False,
#                             color_preemtion_bar = '0.30', color_execution_bar = 'lightblue', title = 'Gantt',
#                             number_xticks=30)
# print("%s:")



