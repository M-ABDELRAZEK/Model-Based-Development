classdef RobotArmSimulation < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                   matlab.ui.Figure
        StopButton                 matlab.ui.control.Button
        Link1LengthEditField       matlab.ui.control.NumericEditField
        Link1LengthEditFieldLabel  matlab.ui.control.Label
        Link2LengthEditField       matlab.ui.control.NumericEditField
        Link2LengthEditFieldLabel  matlab.ui.control.Label
        SimulateButton             matlab.ui.control.Button
        UIAxes                     matlab.ui.control.UIAxes
    end

    properties (Access = private)
        IsStopped logical = false % Description
    end    

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: SimulateButton
        function SimulateButtonPushed(app, event)
            cla(app.UIAxes, "reset")
            app.IsStopped = false;

            linkOneLen = app.Link1LengthEditField.Value;
            linkTwoLen = app.Link2LengthEditField.Value;
            
            thetaOne = linspace(0, 180, 100);
            thetaTwo = linspace(0, 90, 100);
            
            x1 = linkOneLen * cosd(thetaOne);
            x2 = x1 + linkTwoLen * cosd(thetaOne + thetaTwo);
            y1 = linkOneLen * sind(thetaOne);
            y2 = y1 + linkTwoLen * sind(thetaOne + thetaTwo);
            
            hold(app.UIAxes, 'on')
            xlim(app.UIAxes, [-(linkOneLen + linkTwoLen + 1) (linkOneLen + linkTwoLen + 1)]);
            ylim(app.UIAxes, [-(linkOneLen + linkTwoLen + 1) (linkOneLen + linkTwoLen + 1)]);       
            title(app.UIAxes, 'Robot Arm Simulation')
            xlabel(app.UIAxes, 'X-Axis')
            ylabel(app.UIAxes, 'Y-Axis')

            p1 = plot(app.UIAxes, [0, x1(1)], [0, y1(1)], 'Color', 'b', 'LineWidth', 3);
            p2 = plot(app.UIAxes, [x1(1), x2(1)], [y1(1), y2(1)], 'Color', 'r', 'LineWidth', 3, 'Marker', 'o');
            
            for i = 1:length(x1)
                
                if app.IsStopped == true
                    break
                end

                linkOneX = [0, x1(i)];
                linkOneY = [0, y1(i)];
                linkTwoX = [x1(i), x2(i)];
                linkTwoY = [y1(i), y2(i)];
                
                delete(p1)
                delete(p2)

                p1 = plot(app.UIAxes, linkOneX, linkOneY, 'Color', 'b', 'LineWidth', 3);
                p2 = plot(app.UIAxes, linkTwoX, linkTwoY, 'Color', 'r', 'LineWidth', 3, 'Marker', 'o');
                legend(app.UIAxes, 'Link One', 'Link Two')

                drawnow
            end
        end

        % Button pushed function: StopButton
        function StopButtonPushed(app, event)
            app.IsStopped = true;
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Name = 'MATLAB App';

            % Create UIAxes
            app.UIAxes = uiaxes(app.UIFigure);
            title(app.UIAxes, 'Robot Arm Simulation')
            xlabel(app.UIAxes, 'X-Axis')
            ylabel(app.UIAxes, 'Y-Axis')
            zlabel(app.UIAxes, 'Z')
            app.UIAxes.Position = [52 116 538 323];

            % Create SimulateButton
            app.SimulateButton = uibutton(app.UIFigure, 'push');
            app.SimulateButton.ButtonPushedFcn = createCallbackFcn(app, @SimulateButtonPushed, true);
            app.SimulateButton.Position = [328 55 100 23];
            app.SimulateButton.Text = 'Simulate';

            % Create Link2LengthEditFieldLabel
            app.Link2LengthEditFieldLabel = uilabel(app.UIFigure);
            app.Link2LengthEditFieldLabel.HorizontalAlignment = 'right';
            app.Link2LengthEditFieldLabel.Position = [45 29 77 22];
            app.Link2LengthEditFieldLabel.Text = 'Link 2 Length';

            % Create Link2LengthEditField
            app.Link2LengthEditField = uieditfield(app.UIFigure, 'numeric');
            app.Link2LengthEditField.Limits = [0.1 5];
            app.Link2LengthEditField.Position = [137 29 100 22];
            app.Link2LengthEditField.Value = 0.1;

            % Create Link1LengthEditFieldLabel
            app.Link1LengthEditFieldLabel = uilabel(app.UIFigure);
            app.Link1LengthEditFieldLabel.HorizontalAlignment = 'right';
            app.Link1LengthEditFieldLabel.Position = [45 79 77 22];
            app.Link1LengthEditFieldLabel.Text = 'Link 1 Length';

            % Create Link1LengthEditField
            app.Link1LengthEditField = uieditfield(app.UIFigure, 'numeric');
            app.Link1LengthEditField.Limits = [0.1 5];
            app.Link1LengthEditField.Position = [137 79 100 22];
            app.Link1LengthEditField.Value = 0.1;

            % Create StopButton
            app.StopButton = uibutton(app.UIFigure, 'push');
            app.StopButton.ButtonPushedFcn = createCallbackFcn(app, @StopButtonPushed, true);
            app.StopButton.Position = [469 54 100 23];
            app.StopButton.Text = 'Stop';

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = RobotArmSimulation

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end