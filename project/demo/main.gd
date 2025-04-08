extends Control

@onready var network_table_instance: NetworkTableInstance = $NetworkTableInstance

var subscriber: NetworkTableGenericSubscriber
var publisher: NetworkTableGenericPublisher


func _ready() -> void:
	network_table_instance.set_server("localhost")
	network_table_instance.start_ds_client()
	network_table_instance.start_client_4("Godot NetworkTables Demo")
	
	subscriber = network_table_instance.get_topic("/CoralMode").generic_subscribe()
	
	var test_publisher_topic = network_table_instance.get_topic("/Test Publisher")
	test_publisher_topic.set_type(3)
	publisher = test_publisher_topic.generic_publish("string")


func _process(delta: float) -> void:
	if subscriber.get_boolean(false):
		publisher.set_string("True")
	else:
		publisher.set_string("False")
