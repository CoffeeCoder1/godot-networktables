extends Control

@onready var network_table_instance: NetworkTableInstance = $NetworkTableInstance

var subscriber


func _ready() -> void:
	network_table_instance.set_server("localhost")
	network_table_instance.start_ds_client()
	network_table_instance.start_client_4("Godot NetworkTables Demo")
	
	subscriber = network_table_instance.get_topic("/CoralMode").generic_subscribe()


func _process(delta: float) -> void:
	print(subscriber.get_boolean(false))
