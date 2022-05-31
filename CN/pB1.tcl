set ns [new Simulator]

$ns color 2 red

$ns rtproto Static 
set traceFile [open pB1.tr w]
$ns trace-all $traceFile
set namFile [open pb1.nam w]
$ns namtrace-all $namFile
proc finish {} {
	global ns namFile traceFile
	$ns flush-trace
	close $traceFile
	close $namFile
	exec nam pb1.nam &
	exit 0
}

set n(1) [$ns node]
set n(2) [$ns node]
set n(3) [$ns node]

$ns duplex-link $n(1) $n(2) 0.5mb 20ms DropTail
$ns duplex-link $n(2) $n(3) 0.5mb 20ms DropTail
$ns queue-limit $n(1) $n(2) 10
$ns queue-limit $n(2) $n(3) 10

$n(1) shape hexagon
$n(1) shape red
$n(3) shape square
$n(3) color blue

set udp0 [new Agent/UDP]
$ns attach-agent $n(1) $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 512
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

set null0 [new Agent/Null]
$ns attach-agent $n(3) $null0

$ns connect $udp0 $null0
$udp0 set fid_ 2
$ns at 0.5 "$cbr0 start"
$ns at 2.0 "$cbr0 stop"
$ns at 2.0 "finish"

$ns run

